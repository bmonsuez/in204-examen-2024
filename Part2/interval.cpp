#include"interval.hpp"
#include<iostream>

void test_if_empty(const interval& anInterval)
{
    if(anInterval.empty())
        std::cout << "Interval est vide\n";
    else
        std::cout << "Interval n'est pas vide\n";
}


int main()
{
    interval i1;
    interval i2(2, 3);
    test_if_empty(i1);
    test_if_empty(i2);
    return 0;}