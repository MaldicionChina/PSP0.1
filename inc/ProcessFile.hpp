//
// Created by alexis on 3/03/16.
//

/******************************************************************/
/* Program Assignment: the program number                                                         */
/* Name: your name                                                                        */
/* Date: the date you started developing the program                   */
/* Description: a short description of the program and what it does        */
/******************************************************************/

#ifndef PSP0_1_PROCESSFILE_HPP
#define PSP0_1_PROCESSFILE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <regex>

class ProcessFile {
public:
    ProcessFile(std::string cppFile/*,std::string hppFile*/);
    int getTotalProgram();
    int getNrMethods();
    int getNrLinesExpecificMethod(std::string methodName);
    std::map<std::string,int> getMapMethods();

private:
    std::string fileCpp;
    /*std::string fileHpp;*/
    int addOneLineToMethod(std::string methodName);
    int countTotalLinesInsideMethods();
    std::map<std::string,int> methods;
    int totalProgramLine = 0;
};
#endif //PSP0_1_PROCESSFILE_HPP
