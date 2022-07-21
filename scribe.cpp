#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include "scribe.h"
#include "filehandler.h"
#define DIVIDER "XXXXXXXXXX"

        
        
        Scribe::Scribe(){

        }
        
        
        Scribe::~Scribe() {

        }

        void Scribe::GetSettings() {
            
            std::vector<std::string> Settings;
            //std::vector<std::string>::iterator Iter_1 = Settings.begin();
            bool swap = true;
            FileHandler HandlerInstance("settings.txt");
            HandlerInstance.GiveSettings(Settings);
            std::vector<std::string>::iterator Iter_1 = Settings.begin();

            //std::cout << "DEBUG POINT 1 REACHED\n";

            //std::cout << DIVIDER << std::endl;
            //std::cout << Settings.size() << std::endl;
            //std::cout << Settings[0] << std::endl;
            //std::cout << *Iter_1 << std::endl;
            //std::cout << Settings.size() << std::endl;

            
            while(true) {

                //std::cout << "DEBUG POINT 1.1 REACHED\n";
                
                if(*Iter_1 == DIVIDER) {
                    //End of phase 1
                    //Iter_1++;
                    break;
                }

                if(swap == true) {
                    Abbreviations.push_back(*Iter_1);
                    Iter_1++;
                    swap = false;
                    //std::cout << "DEBUG POINT 2 REACHED\n";
                }

                else {
                    Definitions.push_back(*Iter_1);
                    Iter_1++;
                    swap = true;
                    //std::cout << "DEBUG POINT 3 REACHED\n";
                }

            
            }

            if (Iter_1 == Settings.end()) {
                return;
            }

            else {
                Iter_1++;
            }

            while(Iter_1 != Settings.end()) {
                Rule_1.push_back(stoi(*Iter_1));
                Iter_1++;

            };// vector.end() returns end + 1 remeber that!
 
        return;
        }

void Scribe::PrintVectors() {

    std::vector<std::string>::iterator Iter_1 = Abbreviations.begin();
    std::vector<std::string>::iterator Iter_2 = Definitions.begin();
    std::vector<int>::iterator Iter_3 = Rule_1.begin();

    if(Iter_1 == Abbreviations.end())
        return;

    do {
        std::cout << "Vec 1: " << *Iter_1 << "\n";
        std::cout << "Vec 2: " << *Iter_2 << "\n";
        Iter_1++;
        Iter_2++;
    }while( Iter_1 != Abbreviations.end());


    if(Iter_3 == Rule_1.end())
        return;


    do {
        std::cout << "Vec 3: " << *Iter_3 << "\n";
        Iter_3++;
    }while( Iter_3 != Rule_1.end());
    

    return;

}

void Scribe::AppendLogs(std::vector<bool> &_UserInput) {

    FileHandler FileHandlerInstance;

    FileHandlerInstance.InputLog(Abbreviations,_UserInput);
    return;
}