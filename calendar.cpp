#include "calendar.h"

Calendar::Calendar(){
    ActivationTime << time(nullptr);
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

