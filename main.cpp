#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "RegExFile.h"

int main() {
    std::ifstream textFile("testcases.txt");
    std::ofstream outputFile("output.txt");
    
    if (!textFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::string> testCases;
    
    while (std::getline(textFile, line)) {
        testCases.push_back(line);
    }

    std::vector<bool> results;
    
    for (const std::string& testCase : testCases) {
        std::string testCaseCopy = testCase;
        std::vector<std::string> temp;
        size_t pos = 0;
        while ((pos = testCaseCopy.find(',')) != std::string::npos) {
            temp.push_back(testCaseCopy.substr(0, pos));
            testCaseCopy = testCaseCopy.substr(pos + 1);
        }
        temp.push_back(testCaseCopy);

        std::string str = temp[0];
        std::string ptn = temp[1];
        results.push_back(re::strSearch(str, ptn));
    }

    for (bool result : results) {
        if (result) {
            outputFile << "True ";
        } else {
            outputFile << "False ";
        }
    }

    textFile.close();
    outputFile.close();
    
    std::cout << "Check the output.txt file for results" << std::endl;

    return 0;
}
