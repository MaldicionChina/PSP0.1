//
// Created by alexis on 3/03/16.
//

#include "ProcessFile.hpp"

ProcessFile::ProcessFile(std::string cppFile,std::string hppFile){
    this->fileCpp = cppFile;
    this->fileHpp = hppFile;

    std::string actualMethod = ""; // Flag to indicate that have not found method yet
    std::string methodName = "--";
    std::regex BeginMethodMatch (".*::.*\\(.*\\).\\{$",std::regex::ECMAScript);
    std::regex EndMethodMatch ("^\\}",std::regex::ECMAScript);
    std::regex regexToExtractMethodName (".*::(\\w+)\\(.*\\).\\{$",std::regex::ECMAScript);
    std::regex desicionAndLoop(".*([:lower:].*).*\\{.*", std::regex::ECMAScript);

    std::regex normalLine(".*;.*", std::regex::ECMAScript);
    std::regex keywords("^#.*",std::regex::ECMAScript);

    std::smatch matchMethodName; // Variable to save method name result of the submatch

    std::ifstream readFileCpp(fileCpp);
    std::ifstream readFileHpp(fileHpp);

    std::string str;


    while (std::getline(readFileCpp, str)) {

       // std::cout<<str<<std::endl;
        if (std::regex_match(str, BeginMethodMatch)) {
            std::regex_search(str, matchMethodName, regexToExtractMethodName);
            methodName = matchMethodName[1];
            if(actualMethod != methodName ) {
                actualMethod = methodName;
                this->addOneLineToMethod(actualMethod); // To Add the last line of each method
                totalProgramLine++;
            }

        } else if (std::regex_match(str,normalLine) || std::regex_match(str,keywords) || std::regex_match(str,desicionAndLoop)) {

            this->addOneLineToMethod(actualMethod); // Add one line to the method that is reading for this program
            totalProgramLine++;
           // std::cout<<"-------------------------- Count to: "<< actualMethod << "Total Lines  "<< totalProgramLine<<std::endl;
        }

    }
/*
    std::map<std::string,int>::iterator it = methods.find(methodName);
    for (it=methods.begin(); it!=methods.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
*/

}

int ProcessFile::getNrMethods() {

    return methods.size();
}

int ProcessFile::getNrLinesExpecificMethod(std::string methodName) {
    std::map<std::string,int>::iterator it = methods.find(methodName);
    if(it!=methods.end()) {
        return it->second;
    }else{
        return -1;
    }
}

int ProcessFile::getTotalProgram(){

    return this->totalProgramLine;
}

int ProcessFile::addOneLineToMethod(std::string methodName) {

    std::map<std::string,int>::iterator it = methods.find(methodName);
    if(it!=methods.end()) { // Is the method name in the map ?
        it->second = it->second + 1;
    }else if(!methodName.empty()){ // Is the method name doesn't exist create a new map entry
        this->methods.insert(std::pair<std::string,int>(methodName,0));
    }

    return 0;
}