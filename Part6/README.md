## 6. Patrons

La classe `interval` est définie pour des entiers `int`. Cependant, il existe d'autres types d'entiers que les entiers de type `int`. En effet, on pourrait définir un interval pour des entiers non signés: `unsigned`, des petits entiers `short`, des grands entiers `long`, voir même des trs grand entiers `long long`.

Transformer la classe `interval` en la paramétrant par le type d'entier.

Pour rappel, le squelette de la classe est le suivant :

```cpp
class interval
{    
...
public:

    using value_type=...;
    using refence=...;
    using const_reference=...;
    using iterator=...;
    using size_type=...;

    struct const_iterator: 
        std::iterator<std::bidirectional_iterator_tag, // iterator_category
            int,                // value_type
            int,                // difference_type
            const int*,         // pointer
            int>
    {
        [Implantation de la class const_iterator]
    };
...
    bool operator == (const interval&) const {...}
    bool operator != (const interval&) const {...}

    const_iterator begin() const;
    const_iterator end() const;

    bool empty() const {...}
    size_type size() const const {...}

    interval() {...}
    interval(int lowerBound, int upperBound) {...}
    explicit interval(int lowerAndUpperBound) {...}
...
};
```

### Question 6.1

Transformer la classe en un patron de classes (Template). 

___

** Correction **

Il suffit de remplacer toutes les références au type `int` par des références au type `value_type` et d'indiquer que le type `value_type` est l'alias d'un type paramètre `T`.

```cpp
template<typename T>
    requires std::integral<T>
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
        const_iterator(const interval& anInterval, int aValue): 
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
            if(mCurrent <= mInterval->mUpperBound)
                mCurrent ++;
            return *this;
        }
        const_iterator operator --(int)
        {
            const_iterator iterator = *this;
            if(mCurrent <= mInterval->mUpperBound)
                mCurrent ++;
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

    size_type size() const
    {
        return mUpperBound - mLowerBound + 1;
    }

    bool operator != (const interval& anotherInterval) const
    {
        return mUpperBound != anotherInterval.mUpperBound
            || mLowerBound != anotherInterval.mLowerBound;
    }
};
```
___

### Question 6.2

Dites parmi les définitions suivantes :

* Celles qui sont correctes,
* Celles qui ne compilent pas.

| Instanciation | Compile |
|-------|-------|
`interval<int>`||
`interval<long unsigned>`||
`interval<double>`||
`interval<std::string>`||

___

** Correction **

| Instanciation | Compile |
|-------|-------|
| `interval<int>` |  Compile et est correct.| 
| `interval<long unsigned>`|  Compile et est correct.| 
| `interval<double>`|  Compile mais n'est pas correct. En effet, nous manipulons des nombres à virgule flottant et l'énumération ne va pas retourner les entiers dans l'interval. | 
| `interval<std::string>` | Ne compile pas parce qu'il n'est pas possible d'ajouter un entier ou d'enlever un entier à un chaîne de caractères. |

___


### Question 6.3

Nous souhaitons définir en C++20 des contraintes sur le type paramètre de la classe `T`. 

Sachang que le prédicat: [`std::is_integral`](https://en.cppreference.com/w/cpp/types/is_integral) qui est défini dans `<type_traits>`
 est vrai si le type est un entier, comment pouvons nous utiliser ce prédicat pour restreindre les paramètres de type aux seuls entiers ?

___

** Correction **

Il est nécessaire que le paramètre de type `T` vérifie la contrainte exprimée par le prédicat `std::is_integral`. Pour ce faire, il est nécessaire d'ajouter cette contrainte à la déclaration de la classe:

```cpp
template<typename T>
    requires std::integral<T>
class interval
{
    ...
};
```

qui s'assurera que le type paramètre de type `T` est bien un type entier.

Une autre syntaxe, puisque la contrainte ne porte que sur le seul type `T` et qui est équivalente est la suivante :

```cpp
template<std::integral T>
class interval
{
    ...
};
```

___
