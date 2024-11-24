#pragma once
#include<iterator>
#include<type_traits>
#include<stdexcept>

template<std::integral T>
class interval
{
public:
    using value_type = T;
    using const_reference = value_type;
    using reference = value_type;

private:
    value_type mLowerBound;
    value_type mUpperBound;

public:
    struct const_iterator: 
        std::iterator<
            std::bidirectional_iterator_tag, // iterator_category
            value_type,                    // value_type
            value_type,                    // difference_type
            const value_type*,             // pointer
            value_type>
    {
    private:
        const interval* mInterval;
        int mCurrent;

    public:
        const_iterator(const interval& anInterval, int aValue) noexcept(true): 
            mInterval(&anInterval)
        {}        
        reference operator*() const  noexcept(true) 
        { 
            return mCurrent; 
        }
        bool operator == (const const_iterator& anotherIterator) const noexcept(true)
        {
            return mInterval == anotherIterator.mInterval
                && mCurrent == anotherIterator.mCurrent;
        }
        bool operator !=  (const const_iterator& anotherIterator) const noexcept(true)
        {
            return mInterval != anotherIterator.mInterval
                || mCurrent != anotherIterator.mCurrent;
        }
        const_iterator& operator ++() noexcept(true)
        {
            if(mCurrent <= mInterval->mUpperBound)
                mCurrent ++;
            return *this;
        }
        const_iterator operator ++(int) noexcept(true)
        {
            const_iterator iterator = *this;
            if(mCurrent <= mInterval->mUpperBound)
                mCurrent ++;
            return iterator;
        }
        const_iterator& operator --() noexcept(true)
        {
            if(mCurrent <= mInterval->mUpperBound)
                mCurrent ++;
            return *this;
        }
        const_iterator operator --(int) noexcept(true)
        {
            const_iterator iterator = *this;
            if(mCurrent <= mInterval->mUpperBound)
                mCurrent ++;
            return iterator;
        }
    };

    using iterator = const_iterator;
    using size_type = value_type;

    interval() noexcept(true): mLowerBound(0), mUpperBound(-1)
    {}
    explicit interval(int theLowerAndUpperBound) noexcept(true):
        interval(theLowerAndUpperBound, theLowerAndUpperBound)
    {}

    interval(int theLowerBound, int theUpperBound) noexcept(false):
        mLowerBound(theLowerBound), mUpperBound(theUpperBound)
    {
        if(mLowerBound > mUpperBound)
            throw std::out_of_range("Upper bound is less than lower bound.");
    }

    interval(const interval&) = default; 

    int lower() const noexcept(true)
    {
        return mLowerBound;
    }
    int upper() const noexcept(true)
    {
        return mUpperBound;
    }
    bool empty() const noexcept(true)
    {
        return mUpperBound < mLowerBound;
    }

    size_type size() const noexcept(true)
    {
        return mUpperBound - mLowerBound + 1;
    }

    const_iterator begin() const noexcept(true)
    {
        return const_iterator(*this, mLowerBound);
    }

    const_iterator end() const noexcept(true) 
    {
        return const_iterator(*this, mUpperBound + 1);
    }

    bool operator == (const interval& anotherInterval) const noexcept(true)
    {
        return mUpperBound == anotherInterval.mUpperBound
            && mLowerBound == anotherInterval.mLowerBound;
    }

    bool operator != (const interval& anotherInterval) const noexcept(true)
    {
        return mUpperBound != anotherInterval.mUpperBound
            || mLowerBound != anotherInterval.mLowerBound;
    }
};
