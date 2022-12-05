#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include "scribe.h"
#include "calendar.h"
#include "menu.h"
#include "filehandler.h"
#include "multi.h"


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


    //time_t TimeStamp_ = test_1.GetTime();





    // TODO
    // FILEHANDLER, APPENDING LOGS WORKS INCORRECTLY



 

   //FileHandler TestInstance("logs.txt");
   //TestInstance.GetFromLogs();

  // std::vector<std::string> TestVec_1 = TestInstance.GetAllLogs();

/* 
    Scribe TestInstance_Scribe;
    TestInstance_Scribe.ReadLogs();
    int X = TestInstance_Scribe.ExtractTime();
    std::cout << X;
    bool XX = TestInstance_Scribe.checkTwentyFourHours(X);
    std::cout << XX;
 
 */


    //Menu MenuInstance;
    //MenuInstance.Working();

/*
    Scribe T1;
    T1.GetSettings();
    T1.AddOption("ABC","Alphabet",true);
    T1.GetSettings();
    //T1.PrintVectors();
    T1.DeleteOption("ABC");
    T1.GetSettings();
    T1.DeleteOption("ENG");
    T1.GetSettings();
*/

    MultiThread T;
    std::cout << "No. of threads: " << T.checkNumThreads();



    return 0;
}