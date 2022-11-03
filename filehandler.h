#pragma once 

class FileHandler {

    private:
    FileHandler();
        std::string Name;
        int NumberOfLines;


    public:
    FileHandler(std::string _InName);
    ~FileHandler();
    std::string GetFromLogs();
    std::string GetLineNumber(int _LineNumber);
    void GetLinesToVector(int _LineStart, int _LineStop, std::vector<std::string> &_TargetVectoer);
    void GiveSettings(std::vector<std::string> &_TargetVector);
    bool InputLog(std::vector<std::string> &_SourceTarget, std::vector<bool> &_TargetVector2 );
    bool ModifySettings(std::vector<std::string> &_SourceTarget);
    std::vector<std::string> GetAllLogs();

    void PrintProperties();

};