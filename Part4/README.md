## 4. Opérateurs de comparaison

Nous souhaitons définir un opérateur qui détermine si deux objets **interval** désignent le même interval.

### Question 4.1

Proposer une implantation des deux opérateurs suivants :

```cpp
class interval
{
...
public:
...
    bool operator == (const interval&) const;
    bool operator != (const interval&) const;
...
};
```

___

**Correction**

```cpp

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
```

Il suffit de déterminer si les champs internes sont égaux. 

___