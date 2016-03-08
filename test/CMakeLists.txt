

# Enable ExternalProject CMake module
include(ExternalProject)

# Command to build gtest libraries
ExternalProject_Add(
        gtest
#        Changed to download the zip because codeship doesn't allows install debian packages
#        URL /usr/src/gtest
#        BINARY_DIR gtest
        URL https://googletest.googlecode.com/files/gtest-1.7.0.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
# Disable install step
        INSTALL_COMMAND ""
)

# Create a libgtest target to be used as a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

ExternalProject_Get_Property(gtest source_dir binary_dir)
set_target_properties(libgtest PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/libgtest.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
#    "INTERFACE_INCLUDE_DIRECTORIES" "${source_dir}/include"
)
# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${source_dir}/include")


set(SOURCE_FILES main.cpp ProcessFileTest.cpp)
add_executable(TEST ${SOURCE_FILES})

target_link_libraries(TEST libgtest processFile pthread)