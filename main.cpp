#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include "calendar.h"
#include "menu.h"
#include "filehandler.h"
#include "scribe.h"

int main () {
    /*
    std::cout << "Hello World\n";
    Calendar test_1;
    test_1.test_1();

    Menu t_1;
    




    t_1.ShowOptions();

    FileHandler t_2;

    t_2.GetFromLogs();

    t_2.PrintProperties();

    std::string A = t_2.GetLineNumber(3);
    std::cout << A << "\n";

    std::vector<std::string> TestVector;

    t_2.GetLinesToVector(8,12,TestVector);

    for(int i = 0; i < TestVector.size(); i++){
        std::cout << TestVector[i];
    }

    std::cout << TestVector.size();
    */
    Scribe t_10;

    t_10.GetSettings();

    t_10.PrintVectors();






    return 0;
}