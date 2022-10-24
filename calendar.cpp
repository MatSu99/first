#include <string>
#include <iostream>
#include <ctime>
#include "calendar.h"



Calendar::Calendar(){
    ActivationTime = time(nullptr);
/*     std::cout << "\n ACTIVATION TIME: " << ActivationTime << std::endl;
    std::cout<< "\n ACTIVATION TIME(INT): " <<(int)ActivationTime << std::endl;
    std::cout<< "\n ACTIVATION TIME(STRING): " <<std::to_string(ActivationTime) << std::endl; */
}

Calendar::~Calendar(){

}

time_t Calendar::TimeFromPrevious(time_t & A, time_t & B) {

    return difftime(A,B);
}

std::string Calendar::GetReadableTime(time_t & A) {
    
    return ctime(&A);
}

void Calendar::test_1() {

    time_t  a = time(nullptr);


    std::string temp_1;
    temp_1 = temp_1 + ctime(&a);

    std::cout << a << "\n";
    std::cout << temp_1 << "\n";




}

int Calendar::GetTime() {


    return (int)ActivationTime;
}

std::string Calendar::GetTime2() {
    time_t A = time(nullptr);

    return std::to_string(A);
}