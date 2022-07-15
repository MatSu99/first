#pragma once 

class FileHandler {

    private:
        std::string Name;

    public:
    FileHandler();
    FileHandler(std::string In_Name);
    ~FileHandler();
    std::string GetFromLogs();


};