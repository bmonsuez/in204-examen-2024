#include"interval.hpp"
#include<iostream>

template<typename charT, typename T>
void enumerate (
    std::basic_ostream<charT>& output_stream, 
    const interval<T>& anInterval)
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
    interval<int> empty;
    enumerate(std::cout, empty);
    interval<long> fromTo(1, 3);
    enumerate(std::cout, fromTo);
    interval<unsigned> singleton(2);
    enumerate(std::cout, singleton);
    interval<long> acopy;
    enumerate(std::cout, acopy);
    try
    {
        acopy = interval<long>(234, -23);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}