## 5. Containeur

Nous souhaitons que la classe `interval` soit un containeur. En effet, un object `interval` est en mesure de lister l'ensemble des valeurs comprises entre `mLowerBound` et `mUpperBound`. Nous rappelons rapidement les types et comportements que doit définir un containeur :

| Type | Description |
|------|-------------|
`value_type` | Type des valeurs stockées dans le containeur  (T) |
`reference`  | Type référence des valeurs stockées dans le containeur (T&) |
`const_reference`  | Type référence non modifiable des valeurs stockées dans le containeur (const T&) |
`iterator` | Itérateur référençant les valeurs stockées dans le containeur et autorisant la modification de celles-ci |
`const_iterator` | Itérateur référençant les valeurs stockées dans le containeur mais ne permettant pas de modifier le contenu du containeur. |
`size_type` | Type permettant d'exprimer le nombre d'éléments stockés dans le containeur (unsigned long) |

| Expression | Type de retour | Description |
|------------|----------------|-------------|
| `c.begin()` | `(const_)iterator` | Itérateur référençant le premier élément stocké dans le containeur |
| `c.end()` | `(const_)iterator` | Itérateur référençant l'élément dénotant la fin de la séquence |
| `c.empty()` | `bool` | Aucun élément dans le containeur |
| `c.size()` | `size_type` | Nombre d'éléments dans le containeur. |

### Question 5.1

Est-il est possible de modifier le contenu de l'interval en utilisant un itérateur les valeurs dans le containeur ?

**Remarque** : Seul la borne inférieure et la borne supérieure de l'intervalle sont définies, les autres valeurs sont immutables.

___

**Correction**

Les valeurs présentes dont l'interval sont l'ensemble des entiers situés entre la borne inférieure et la borne supérieure. C'est valeurs sont immuables. En effet, la valeur est toujours le successeur de la valeur précédente et le prédécesseur de la valeur suivante. Il n'est donc pas possible de modifier la valeur à laquelle un itérateur fait référence.
___

### Question 5.2

Si le containeur n'est pas modifiable, expliquer pourquoi 
* il n'y a qu'une seule définition des fonctions membres `begin()` et `end()`,
* `reference`, `const_reference` désignent le même type,
* `reference`, `const_reference` sont le plus souvent des alias de `value_type`.


```cpp
class interval
{    
...
public:
...
    bool operator == (const interval&) const;
    bool operator != (const interval&) const;

    const_iterator begin() const;
    const_iterator end() const;
...
};
```

**Correction**

1. Normalement, il y deux fonctions membres `begin()`:


```cpp
    const_iterator begin() const;
    iterator begin();
```

La première fonction membre a l'attribut `const`, elle retourne un `const_iterator` qui ne permet pas de modifier la donnée dans le containeur auquel l'itérateur fait référence. 

La seconde fonction membre n'a pas l'attribut `const`, elle retourne un `iterator`qui autorise de remplacer la donnée dans le containeur auquel l'itérateur fait référence par une autre valeur.

Comme nous ne pouvons pas modifier les données présentes dans l'interval, la deuxième fonction membre:

```cpp
    iterator begin();
```

2. Comme il n'est pas possible de modifier la donnée auquel le containeur fait référence, la référence a soit le type `const value_type&`, ie. est une référence sur l'adresse mémoire à laquelle la donnée est stockée ou au contraire `value_type`, ie. est une copie de la donnée stockée dans l'interval.

3. Dans le cas de l'interval, comme les valeurs ne sont pas véritablement stockée dans le containeur, `const_reference` et `reference` sont égaux à `value_type` qui lui même est égal à `int`.

___

### Question 5.3

Nous vous proposons le squelette de la classe `const_iterator` suivant:

```cpp
class interval
{    
...
public:

    struct const_iterator: 
        std::iterator<std::bidirectional_iterator_tag, // iterator_category
            int,                    // value_type
            int,                    // difference_type
            const int*,             // pointer
            int>
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
        bool operator == (const const_iterator& anotherIterator) const
        {
            return mInterval == anotherIterator.mInterval
                && mCurrent == anotherIterator.mCurrent;
        }
        bool operator !=  (const const_iterator& anotherIterator) const
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
...
    bool operator == (const interval&) const {...}
    bool operator != (const interval&) const {...}

    const_iterator begin() const;
    const_iterator end() const;

    bool empty() const {...}

    interval() {...}
    interval(int lowerBound, int upperBound) {...}
    explicit interval(int lowerAndUpperBound) {...}
...
};
```

Expliquer quel est le type de l'itérateur (input, output, forward, bidirectional ou random access) ? 


___

** Correction **

L'itéateur est un bidirectional iterator. Il ne permet pas de modifier la valeur, il n'est donc pas un ouput iterator, 
il ne permet pas d'aller à n'importe qu'elle valeur dans l'interval, puisqu'il n'est possible d'aller qu'à l'élément suivant et précédent. 

___

### Question 5.4

Proposer une implantation des fonctions:

```cpp
    const_iterator begin() const;
    const_iterator end() const;
```

de la classe `interval`.

___

** Correction **

La fontion `begin()` retourne le premier élément dans le containeur ou sinon est égal à `end()`. Le premier élément a pour valeur `mLowerBound`, il suffit donc de créer un itérateur qui a cette valeur.

```cpp
    const_iterator begin() const
    {
        return const_iterator(*this, mLowerBound);
    }
```

Pour la fonction `end()`, il retourne l'élément dans le containeur qui est l'élément situé juste après le dernier élément du containeur. Ici, le dernier élément de l'interval a pour valeur : `mUpperBound`, l'élément suivant est obtenur pas `mUpperBound + 1`. Il suffit donc de créer un itérateur qui a cette valeur.

```cpp
    const_iterator end() const
    {
        return const_iterator(*this, mUpperBound + 1);
    }
```

___

Nous avons implanté le type `const_iterator` ainsi que les fonction `const_iterator begin() const` et `const_iterator end() const`. Nous devons désormais implanter les autres types:

| Type | Description |
|------|-------------|
`value_type` | Type des valeurs stockées dans le containeur  (T) |
`reference`  | Type référence des valeurs stockées dans le containeur (T&) |
`const_reference`  | Type référence non modifiable des valeurs stockées dans le containeur (const T&) |
`iterator` | Itérateur référençant les valeurs stockées dans le containeur et autorisant la modification de celles-ci |
`const_iterator` | Itérateur référençant les valeurs stockées dans le containeur mais ne permettant pas de modifier le contenu du containeur. |
`size_type` | Type permettant d'exprimer le nombre d'éléments stockés dans le containeur (unsigned long) |

**Rappel**: Pour définir un alias de type dans une classe, par exemple dans une classe `number` un type `float_type` qui est égal à `double` comme suit :

```cpp
class number:
{
public:
    using float_type = double;

    float_type zero() const { return 0.0; }
};
```

Implanter les types qui n'ont pas été encore défini en utilisant des alias de types.


___

** Correction **

Comme précédemment indiqué, `value_type` est un alias du type `int`, `reference` et `const_reference` sont des alias du type `value_type`.
```cpp
    using value_type = int;
    using reference = value_type;
    using const_reference = value_type;
```    

Comme il n'existe que des `const_iterator` puisque le contenu d'un interval n'est pas modifiable, `iterator` est un alias du type `const_iterator`.
```cpp
    using iterator = const_iterator;
```

Enfin le type désignant le nombre d'élément est un entier, il doit avoir la même taille que les entiers qui forment les bornes de l'interval, dont c'est un alias du type `value_type`.
```cpp
    using size_type = value_type;
```
___

### Question 5.5

| Expression | Type de retour | Description |
|------------|----------------|-------------|
| `c.empty()` | `bool` | Aucun élément dans le containeur |
| `c.size()` | `size_type` | Nombre d'éléments dans le containeur. |

Il reste ces deux fonctions. La fonction `empty()` a déjà été implantée, il ne reste plus qu'à implanter la fonction: `size()`. Proposer le code qui implante la fonction `size()`.

___

** Correction **

La fonction donne le nombre d'entiers dans l'interval et est égale à `mUpperBound - mLowerBound + 1`. Le type de la valeur retournée par la fonction est `size_type`, ceci conduit à écrire le code suivant:

```cpp

    size_type size() const
    {
        return `mUpperBound - mLowerBound + 1;
    }
```
    
