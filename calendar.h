#pragma once
#include <ctime>
#include <string>
#include <iostream>

class Calendar {
    
    private:
    time_t ActivationTime;

    public:
        Calendar();
        ~Calendar();
        void test_1();
        time_t TimeFromPrevious(time_t & A, time_t & B);
        std::string GetReadableTime ( time_t & A);


};