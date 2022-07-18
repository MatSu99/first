#pragma once 

class FileHandler {

    private:
        std::string Name;
        int NumberOfLines;

    public:
    FileHandler();
    FileHandler(std::string _InName);
    ~FileHandler();
    std::string GetFromLogs();
    std::string GetLineNumber(int _LineNumber);
    void GetLinesToVector(int _LineStart, int _LineStop, std::vector<std::string> &_TargetVectoer);
    void GiveSettings(std::vector<std::string> &_TargetVector);

    void PrintProperties();

};