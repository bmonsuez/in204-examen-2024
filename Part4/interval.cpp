#include"interval.hpp"
#include<iostream>

// Overloaded operator to print the content of an interval view (as exposed in the annex)
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

void testIfEqual(const interval& anInterval, const interval& anotherInterval)
{
    std::cout << std::boolalpha
        << anInterval << " == " << anotherInterval << ": "
        << (anInterval == anotherInterval) << std::endl;
}

int main()
{
    interval empty;
    interval copy = empty;
    testIfEqual(empty, copy);
    interval fromTo(1, 3);
    testIfEqual(empty, fromTo);
    interval singleton(2);
    testIfEqual(empty, singleton);
    copy = fromTo;
    testIfEqual(copy, fromTo);
    return 0;
}