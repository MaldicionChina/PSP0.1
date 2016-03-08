//
// Created by alexis on 21/02/16.
//

#include <gtest/gtest.h>
#include "ProcessFile.hpp"

ProcessFile* countFile = new ProcessFile("LinkedListCpp.txt","../inc/ProcessFile.hpp");

TEST(ProcessFile, CountMethods){
            //Expected - Actual
    ASSERT_EQ(5,countFile->getNrMethods());
}

TEST(ProcessFile, CountWholeProgram){
            //Expected - Actual
    ASSERT_EQ(44,countFile->getTotalProgram());
}

TEST(ProcessFile, CountExpecificMethod){
    //Expected - Actual
    ASSERT_EQ(8,countFile->getNrLinesExpecificMethod("addData"));
}

