#include"interval.hpp"
#include<iostream>

int main()
{
    interval empty;
    interval fromTo(1, 3);
    interval singleton(2);
    interval acopy(fromTo);
    return 0;
}