#pragma once

class interval
{
private:
    int mLowerBound;
    int mUpperBound;

public:
    interval(): mLowerBound(0), mUpperBound(-1)
    {}
    explicit interval(int theLowerAndUpperBound):
        mLowerBound(theLowerAndUpperBound), mUpperBound(theLowerAndUpperBound)
    {}
    interval(int theLowerBound, int theUpperBound):
        mLowerBound(theLowerBound), mUpperBound(theUpperBound)
    {}

    interval(const interval&) = default; 

    bool empty() const
    {
        return mUpperBound < mLowerBound;
    }
};
