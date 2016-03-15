#include <iostream>
#include "ProcessFile.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    std::map<std::string,int> mapMethods;

    if (argc < 2)
    {
        cout << "Usage: countProgram pathToCppFile\n";
        return 1;
    }

    ProcessFile* countProgram = new ProcessFile(argv[1]);
    mapMethods = countProgram->getMapMethods();

    std::cout << argv[1] << std::endl;
    std::cout << "Nr Methods :" << countProgram->getNrMethods() << std::endl;


    for (std::map<std::string,int>::iterator it =mapMethods.begin(); it!=mapMethods.end(); ++it) {
        std::cout << " *  " << it->first << " : " << it->second << '\n';
    }

    std::cout << "Nro Total Lines: " << countProgram-> getTotalProgram() << std::endl;

    return 0;
}