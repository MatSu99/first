#pragma once


class Scribe {

    std::vector<std::string> Abbreviations;
    std::vector<std::string> Definitions;
    std::vector<int> Rule_1;
    std::vector<std::string> Logs;

    public:
        Scribe();
        ~Scribe();
        void GetSettings();
        bool AddOption(std::string _Abb, std::string _Def, bool Rule1);
        void DeleteOption(std::string _Abb);
        void ShowDefinitions();
        

        void PrintVectors();
        void AppendLogs(std::vector<bool> &_UserInput);
        void ReadLogs();
        void PrintLogs();

        size_t ExtractTime();
        bool checkTwentyFourHours(int T1);
        bool checkProposedAbb(std::string _Abb);

        // GET METHODS

        int GetSizeAbb();
        int GetSizeDef();
        bool CheckIfRule1(int place);

        std::string GetAbbFrom( int place);
        std::string GetDefFrom ( int place);


        
};