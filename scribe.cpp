#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include "scribe.h"
#include "filehandler.h"
#include "calendar.h"
#define DIVIDER "XXXXXXXXXX"
#define DAY  (size_t)86400      // seconds ( 24*60*60)

        
        
        Scribe::Scribe(){

        }
        
        
        Scribe::~Scribe() {

        }

        void Scribe::GetSettings() {
            
            std::vector<std::string> Settings;
            bool swap = true;
            FileHandler HandlerInstance("settings.txt");
            HandlerInstance.GiveSettings(Settings);
            std::vector<std::string>::iterator Iter_1 = Settings.begin();
            
            while(true) {

                if(*Iter_1 == DIVIDER) {

                    break;
                }

                if(swap == true) {
                    Abbreviations.push_back(*Iter_1);
                    Iter_1++;
                    swap = false;
                }

                else {
                    Definitions.push_back(*Iter_1);
                    Iter_1++;
                    swap = true;
                }

            }

            if (Iter_1 == Settings.end()) {
                return;
            }

            else {
                Iter_1++;
            }

            while(Iter_1 != Settings.end()) {
                Rule_1.push_back(stoi(*Iter_1));    // String to int stoi
                Iter_1++;

            };// vector.end() returns end + 1 remeber that!
 
        return;

        }

void Scribe::ReadLogs()
{
    if(Logs.empty() == false)
    {
        Logs.clear();
    }

    FileHandler HandlerInstance("logs.txt");
    Logs = HandlerInstance.GetAllLogs();

}

void Scribe::PrintLogs()
{

    for(auto& x : Logs)
   {
        std::cout << x;
   }

}

void Scribe::PrintVectors() 
{

    std::vector<std::string>::iterator Iter_1 = Abbreviations.begin();
    std::vector<std::string>::iterator Iter_2 = Definitions.begin();
    std::vector<int>::iterator Iter_3 = Rule_1.begin();
    std::vector<std::string>::iterator Iter_4 = Logs.begin();

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

    PrintLogs();
    
    return;

}

void Scribe::AppendLogs(std::vector<bool> &_UserInput) 
{

    FileHandler FileHandlerInstance;
    FileHandlerInstance.InputLog(Abbreviations,_UserInput);


}

int Scribe::GetSizeAbb() 
{

    return Abbreviations.size();

}

bool Scribe::CheckIfRule1(int place)        // PLACE IN VECTOR A = B+1 PLACE IN TXT FILES (First line is 1 not 0 in txt)
{

    for (int i = 0; i < Rule_1.size(); ++i) {

        if(place+1 == Rule_1[i]) {
            return true;
        }
    }

    return false;

}

std::string Scribe::GetAbbFrom ( int place ) 
{

    if(place > Abbreviations.size())
        return "ERR OUT OF RANGE";

    return Abbreviations[place];

}

std::string Scribe::GetDefFrom ( int place ) 
{

    if(place > Definitions.size())
        return "ERR OUT OF RANGE";

    return Definitions[place];

}

bool Scribe::checkTwentyFourHours(int T1)
{
    Calendar CalendarInstance;
    //std::cout << "\n TIME: " << CalendarInstance.GetTime();
    //std::cout << "\n T: " << T1;
    if(T1 > stoi(CalendarInstance.GetTime2()))
    {
        return false;
    }
    int difference =  CalendarInstance.GetTime() - T1;
    std::cout << "\n DIFF:" << difference << std::endl;

    if(difference < (DAY - 3600))       // 24-1 = 23 hours
    {
        std::cout << "FALSE\n";
        return false;
    }

    std::cout << "TRUE\n";
    return true;


}

size_t Scribe::ExtractTime()        // WARNING, IF LAST LINE IS EMPTY THIS WILL GO DOWN FAST AF BOY
{
    //std::cout << "Start";
    std::string StringFromVec = Logs.back();
    //std::cout << "Start 2";
    int flare = StringFromVec.find(' ');
    //std::cout << "Start 3";

    std::string SubString = StringFromVec.substr(0, flare);

    //std::cout<< SubString;

    return std::stoi(SubString);

}