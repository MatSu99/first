# pragma once
#define NumOfOptions 5

class Menu {

    private:
        std::string Options[NumOfOptions];

    public:

        Menu();
        ~Menu();
        bool Working();
        void ShowOptions();
        int ChooseOption();
        void CheckSettings();
        void Update( Scribe &ScribeInstance);
};