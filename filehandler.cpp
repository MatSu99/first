#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "filehandler.h"
#include "calendar.h"

FileHandler::FileHandler() {
    Name = "logs.txt";
    NumberOfLines = 0;

    std::fstream file;
    file.open(Name, std::ios::in);

    if(file.good()==false) {
        std::cout << "ERROR, CONSTRUCTOR HAVE NOT FOUND " << Name << " file!";
        //return "E";
        throw 100; // To do handling exepctions
    }

    std::string line;

        while(getline(file,line))
    {
        ++NumberOfLines;
    }

    //++NumberOfLines;

    file.close();
}

FileHandler::FileHandler(std::string _InName)
{
    Name = _InName;
    NumberOfLines = 0;

    std::fstream file;
    file.open(Name, std::ios::in);

    if(file.good()==false) {
        std::cout << "ERROR, CONSTRUCTOR HAVE NOT FOUND " << Name << " file!";
        //return "E";
        throw 100; // To do handling exepctions
    }

    std::string line;

    while(getline(file,line))
    {
        ++NumberOfLines;
    }

    //++NumberOfLines;

    file.close();
}

FileHandler::~FileHandler() {

}


std::string FileHandler::GetFromLogs() {

    std::fstream file;
    file.open("logs.txt", std::ios::in);

    if(file.good()==false) {
        std::cout << "ERROR";
        throw 101;
        return "E";
    }

    std::string line;
    int num_line;

    getline(file,line);
    std::cout << line;
    std::cout << "___";

/*     while(getline(file,line))
    {
        std::cout << line;
        std::cout << "_END_\n";
    } */



    file.close();
    // TO DO 

    return line;

}

std::vector<std::string> FileHandler::GetAllLogs() {

    std::fstream file;
    file.open("logs.txt", std::ios::in);
    std::vector<std::string> ToReturnVector;        // You can return this as value since C++11

    if(file.good()==false) {
        std::cout << "ERROR";
        throw 101;
        return ToReturnVector;  // Returning empty vector
    }

       std::string line;
    while(getline(file,line))
    {
        line+='\n';
        ToReturnVector.push_back(line);

    }

    file.close();

    return ToReturnVector;  // You can return this as value since C++11
                            // However, there are some places where 
                            // vector is passed by reference ( in this code)


}

std::string FileHandler::GetLineNumber( int _LineNumber) {

    if(_LineNumber > NumberOfLines) {
        std::cout<< "Number of of range \n";
        return "XXX";
    }

    std::fstream file;
    file.open("logs.txt", std::ios::in);

    if(file.good()==false) {
        std::cout << "ERROR";
        throw 101;
        return "E";
    }

    std::string line;

    for (int i = 0; i<_LineNumber; i++) {

            getline(file,line);

    }

    file.close();

    return line;

}

void FileHandler::PrintProperties() {

    std::cout << "Name of file: "<< Name << "\n";

    std::cout << "Number of lines: "<< NumberOfLines << "\n";

    return;
}

void FileHandler::GetLinesToVector(int _LineStart, int _LineStop, std::vector<std::string> &_TargetVectoer) {

    if( _LineStart < 0 || _LineStart > NumberOfLines) {
        std::cout << "Starting point error\n";
        return;
    }

    if(_LineStop < _LineStart || _LineStop > NumberOfLines) {
        std::cout << "Stoping point error\n";
        return;
    }

    std::fstream file;
    file.open("logs.txt", std::ios::in);

    if(file.good()==false) {
        std::cout << "ERROR";
        throw 101;
        return;
    }

    std::string line;

    int Marker = 1;

    while(Marker < _LineStart) {

        getline(file,line);
        ++Marker;
    }

    while(Marker != _LineStop+1) {

        getline(file,line);
        _TargetVectoer.push_back(line);
        ++Marker;
    }

    file.close();


}

void FileHandler::GiveSettings(std::vector<std::string> &_TargetVector) {

    std::fstream file;
    file.open(Name, std::ios::in);

    if(file.good()==false) {
        std::cout << "ERROR, CONSTRUCTOR HAVE NOT FOUND " << Name << " file!";
        //return "E";
        throw 100; // To do handling exepctions
    }

    std::string line;

    while(getline(file,line))
    {
        _TargetVector.push_back(line);
    }

    //++NumberOfLines;

    file.close();

}

bool FileHandler::InputLog(std::vector<std::string> &_SourceTarget, std::vector<bool> &_TargetVector2 ) {

    Calendar CalendarInstance;

    std::string Log_;

    Log_ = Log_+'\n';

    Log_ = Log_ +  CalendarInstance.GetTime2();

    Log_ = Log_ + ' ';

 

    for(int i = 0; i<_SourceTarget.size(); ++i) {
        
        Log_ = Log_ + _SourceTarget[i]+ ':' + std::to_string(_TargetVector2[i]) + ' ';

    }

    Log_.pop_back();


    //Log_ = Log_+'\n';

    std::fstream file;
    file.open(Name, std::ios::app);

    if(file.good()==false) {
        std::cout << "ERROR, CONSTRUCTOR HAVE NOT FOUND " << Name << " file!";
        //return "E";
        return false;
        //throw 100; // To do handling exepctions
    }

    file << Log_;

    file.close();


    return true;

    



    //Log_ = Log_ + CalendarInstance.GetTime();




}