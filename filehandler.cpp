#include "filehandler.h"

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
    std::cout << "___";

    while(getline(file,line))
    {
        std::cout << line;
        std::cout << "_END_\n";
    }


    file.close();
    // TO DO 

    return line;

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