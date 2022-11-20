#include <iostream>
#include <vector>
#include "scribe.h"
#include "menu.h"

Menu::Menu() {

    Options[0] = "[0] Update logs";
    Options[1] = "[1] Print vectors";
    Options[2] = "[2]";
    Options[3] = "[3]";
    Options[4] = "[4] EXIT";

}

Menu::~Menu() {

}


void Menu::ShowOptions() {
    
    for(auto& i : Options) {
        std::cout << i << "\n";
    }

}


int Menu::ChooseOption() {

    int option = 0;
    char confirm = 'N';

    while(true) {
        start:
        ShowOptions();

        while(true) {
            
            std::cout << "Enter number of option: ";
            std::cin >> option;
            
            if(std::cin.fail() == true) {
                std::cin.clear();
                std::cin.ignore(1000,'\n');
            }   
            else {
                break;
            }

        }





        switch(option) {
            case 0:
                std::cout << "Confirm option: " << Options[0] << "(Y/N)\n";
                //
                break;

            case 1:
                std::cout << "Confirm option: " << Options[1] << "(Y/N)\n";
                //
                break;

            case 2:
                std::cout << "Confirm option: " << Options[2] << "(Y/N)\n";
                //
                break;
            
            case 3:
                std::cout << "Confirm option: " << Options[3] << "(Y/N)\n";
                //
                break;

            case 4:
                std::cout << "Confirm option: " << Options[4] << "(Y/N)\n";
                //
                break;

            case 5:
                std::cout << "Confirm option: " << Options[5] << "(Y/N)\n";
                //
                break;
            default:
                std::cout << "No valid option has been choosen, please try again\n";
                goto start;
                //break;



        }

        while(true) {
            
            //std::cout << "Y/N ";
            std::cin >> confirm;
            
            if(std::cin.fail() == true) {
                std::cin.clear();
                std::cin.ignore(1000,'\n');
            }   
            else {
                break;
            }

        }

        if(confirm == 'Y' || confirm == 'y') {
            return option;
        }
        else {
            goto start;
        }

        


    };

    // Error
    return 0;
}

void Menu::CheckSettings() {

    Scribe ScribeInstance;

    ScribeInstance.GetSettings();
    ScribeInstance.PrintVectors();

    return;

}

bool Menu::Working() {

    int decisoon = 0;

    Scribe ScribeInstance;
    ScribeInstance.GetSettings();
    ScribeInstance.ReadLogs();

    while(true) {

        decisoon = ChooseOption();

        if(decisoon == 4)
            break;
        
        if(decisoon == 0) {

            Update(ScribeInstance);

        }
        if(decisoon == 1) {
            ScribeInstance.PrintVectors();
        }
        if(decisoon == 2) {

        }
        if(decisoon == 3) {

        }
    }

    return true;
}

void Menu::Update(Scribe &ScribeInstance) {

    bool check_time = ScribeInstance.checkTwentyFourHours(ScribeInstance.ExtractTime());

    if(check_time == true)
    {
        //
    }
    else
    {
        std::cout << "WARNING !!! LAST UPDATE DONE IN LESS THAN 23 HOURS\n";
    }

    std::vector<bool> UserInput;
    char input_1 = 'N';

    for(int i = 0; i < ScribeInstance.GetSizeAbb(); ++i) {

        checkpoint_1:

        std::cout << "UPDATE [" << i+1 <<"] " << ScribeInstance.GetDefFrom(i) << "\n";

        while(true) {
            
            //std::cout << "Y/N ";
            std::cin >> input_1;
            
            if(std::cin.fail() == true) {
                std::cin.clear();
                std::cin.ignore(1000,'\n');
            }   
            else {
                break;
            }

        }

        if(input_1 == 'Y' || input_1 == 'y') {
            UserInput.push_back(1);
        }
        else if(input_1 == 'N' || input_1 == 'n') {
            UserInput.push_back(0);
        }
        else
            goto checkpoint_1;



    }

    ScribeInstance.AppendLogs(UserInput);

    std::cout << "LOGS UPDATED!\n";

    ScribeInstance.ReadLogs();

    return;
}

void Menu::UpdateSettings( Scribe &ScribeInstance)
{
    
}