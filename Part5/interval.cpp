#include"interval.hpp"
#include<iostream>

template<typename charT>
void enumerate (
    std::basic_ostream<charT>& output_stream, 
    const interval& anInterval)
{
    output_stream << "{";
    bool nextElement = false;
    for(auto it = anInterval.begin();
        it != anInterval.end();
        it ++)
    {
        if(nextElement)
            output_stream << ", ";
        output_stream << *it;
    }
    output_stream << "}";
}

int main()
{
    interval empty;
    enumerate(std::cout, empty);
    interval fromTo(1, 3);
    enumerate(std::cout, fromTo);
    interval singleton(2);
    enumerate(std::cout, singleton);
    interval acopy(fromTo);
    enumerate(std::cout, acopy);
    return 0;
}