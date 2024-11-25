#pragma once

#include<iterator>

class interval
{
private:
    int mLowerBound;
    int mUpperBound;

public:
    using value_type = int;
    using const_reference = value_type;
    using reference = value_type;

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
        const_iterator(const interval& anInterval, value_type aValue): 
            mInterval(&anInterval)
        {}        
        reference operator*() const 
        { 
            return mCurrent; 
        }
        bool operator == (const const_iterator& anotherIterator)
        {
            return mInterval == anotherIterator.mInterval
                && mCurrent == anotherIterator.mCurrent;
        }
        bool operator !=  (const const_iterator& anotherIterator)
        {
            return mInterval != anotherIterator.mInterval
                || mCurrent != anotherIterator.mCurrent;
        }
        const_iterator& operator ++()
        {
            if(mCurrent <= mInterval->mUpperBound)
                mCurrent ++;
            return *this;
        }
        const_iterator operator ++(int)
        {
            const_iterator iterator = *this;
            if(mCurrent <= mInterval->mUpperBound)
                mCurrent ++;
            return iterator;
        }
        const_iterator& operator --()
        {
            if(mCurrent >= mInterval->mLowerBound)
                mCurrent --;
            return *this;
        }
        const_iterator operator --(int)
        {
            const_iterator iterator = *this;
            if(mCurrent >= mInterval->mLowerBound)
                mCurrent --;
            return iterator;
        }
    };

    using iterator = const_iterator;
    using size_type = value_type;

    interval(): mLowerBound(0), mUpperBound(-1)
    {}
    explicit interval(int theLowerAndUpperBound):
        mLowerBound(theLowerAndUpperBound), mUpperBound(theLowerAndUpperBound)
    {}
    interval(int theLowerBound, int theUpperBound):
        mLowerBound(theLowerBound), mUpperBound(theUpperBound)
    {}

    interval(const interval&) = default; 

    int lower() const
    {
        return mLowerBound;
    }
    int upper() const
    {
        return mUpperBound;
    }
    bool empty() const
    {
        return mUpperBound < mLowerBound;
    }

    size_type size() const
    {
        return mUpperBound - mLowerBound + 1;
    }

    const_iterator begin() const
    {
        return const_iterator(*this, mLowerBound);
    }

    const_iterator end() const
    {
        return const_iterator(*this, mUpperBound + 1);
    }

    bool operator == (const interval& anotherInterval) const
    {
        return mUpperBound == anotherInterval.mUpperBound
            && mLowerBound == anotherInterval.mLowerBound;
    }

    bool operator != (const interval& anotherInterval) const
    {
        return mUpperBound != anotherInterval.mUpperBound
            || mLowerBound != anotherInterval.mLowerBound;
    }
};
