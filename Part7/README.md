
## 7. exceptions

Le constructeur 
```cpp
    interval(int lowerBound, int upperBound);
```
n'implante pas de vérification. Cependant, si `lowerBound` ne peut pas être plus grand que `upperBound`. Si c'est le cas, l'interval créé n'est pas valide. Nous souhaitons que lors de la construction de l'interval, nous vérifions que `lowerBound` n'est pas plus grand que `upperBound`.
Si `lowerBound` est plus grand que `upperBound`, la construction de l'interval doit échouer et nous devons lever une exception `std::out_of_range`.

### Question  7.1

Modifier le code du constructeur pour vérifier la condition et lever l'exception si la condition n'est pas validé.

___

**Correction**

Il suffit d'ajouter le code dans le constructeur qui vérifie que `lowerBound` est plus petit ou égal à `upperBound` et si ce n'est le cas, lève l'exception `std::out_of_range`.

```cpp
    interval(int theLowerBound, int theUpperBound):
        mLowerBound(theLowerBound), mUpperBound(theUpperBound)
    {
        if(mLowerBound > mUpperBound)
            throw new std::out_of_range("Upper bound is less than lower bound.")
    }
```    

___
### Question  7.2

Modifier l'entête de la fonction pour indiquer qu'un exception peut-être levée.


___

**Correction**

Il suffit d'indiquer un attribut `noexcept(false)` pour indiquer que le constructeur peut lever une exception.

```cpp
    interval(int theLowerBound, int theUpperBound) noexcept(false):
        mLowerBound(theLowerBound), mUpperBound(theUpperBound)
    {
        if(mLowerBound > mUpperBound)
            throw new std::out_of_range("Upper bound is less than lower bound.")
    }
```    

En fait, il n'y a aucune raison de s'arrêter aux constructeurs, nous pouvons ensuite indiquer pour toutes les fonctions membres, si cette fonction peut lever ou ne lève pas d'exception en mettrant soit  `noexcept(false)` ou  `noexcept(true)`. 

