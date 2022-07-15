#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include "calendar.cpp"
#include "menu.cpp"
#include "filehandler.cpp"

int main () {

    std::cout << "Hello World\n";
    Calendar test_1;
    test_1.test_1();

    Menu t_1;
    t_1.ShowOptions();

    FileHandler t_2;


    return 0;
}