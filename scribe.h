#pragma once


class Scribe {

    std::vector<std::string> Abbreviations;
    std::vector<std::string> Definitions;
    std::vector<int> Rule_1;

    public:
        Scribe();
        ~Scribe();
        void GetSettings();
        void AddOption();
        void ShowDefinitions();
        

        void PrintVectors();
        void AppendLogs(std::vector<bool> &_UserInput);

        
};