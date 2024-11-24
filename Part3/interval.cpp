#include"interval.hpp"
#include<iostream>

template<typename charT>
std::basic_ostream<charT>& operator << (
    std::basic_ostream<charT>& output_stream, 
    const interval& anInterval)
{
    if(anInterval.empty())
        output_stream << "[]";
    else
        output_stream << "[" << anInterval.lower() << ".." << anInterval.upper() << "]";
    return output_stream;
}

int main()
{
    interval empty;
    std::cout << empty << std::endl;
    interval fromTo(1, 3);
    std::cout << fromTo << std::endl;
    interval singleton(2);
    std::cout << singleton << std::endl;
    interval acopy(fromTo);
    std::cout << acopy << std::endl;
    return 0;
}