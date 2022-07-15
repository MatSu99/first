#include "filehandler.h"

FileHandler::FileHandler() {
    Name = "logs.txt";

}

FileHandler::FileHandler(std::string In_Name)
{
    Name = In_Name;
}

FileHandler::~FileHandler() {

}


std::string FileHandler::GetFromLogs() {

    std::fstream file;
    file.open("logs.txt", std::ios::in);

    if(file.good()==false) {
        std::cout << "ERROR";
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