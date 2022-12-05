#include <iostream>
#include <vector>
#include <thread>
#include "multi.h"

MultiThread::MultiThread()
{

}

MultiThread::~MultiThread()
{

}

int MultiThread::checkNumThreads()
{
    return std::thread::hardware_concurrency();
}