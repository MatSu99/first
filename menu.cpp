#include <iostream>
#include "menu.h"

Menu::Menu() {

    Options[0] = "Op1";
    Options[1] = "Op2";
    Options[2] = "Op3";
    Options[3] = "Op4";
    Options[4] = "Op5";

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

            case 1:
                std::cout << "Confirm option: " << Options[0] << "(Y/N)\n";
                //
                break;

            case 2:
                std::cout << "Confirm option: " << Options[1] << "(Y/N)\n";
                //
                break;
            
            case 3:
                std::cout << "Confirm option: " << Options[2] << "(Y/N)\n";
                //
                break;

            case 4:
                std::cout << "Confirm option: " << Options[3] << "(Y/N)\n";
                //
                break;

            case 5:
                std::cout << "Confirm option: " << Options[4] << "(Y/N)\n";
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