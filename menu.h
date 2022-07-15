# pragma once

#define NumOfOptions 5

class Menu {

    private:

    std::string Options[NumOfOptions];

    public:

    Menu();
    ~Menu();
    void ShowOptions();
    int ChooseOption();
};