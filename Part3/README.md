### 3. Les données stockées au sein de la classe [Correction]

### Question 3.1

Est-il possible d'accéder aux champs `mLowerBound`, `mUpperBound` en dehors de la classe `interval` ? Expliquer pourquoi ?

___

**Correction**

Non, car les champs `mLowerBound`, `mUpperBound` sont des champs privés, seules les fonctions membres de la classe `interval`
peuvent y accéder.
___

### Question 3.2

Proposer un moyen pour pouvoir accéder en lecture aux données stockées dans ces champs, mais surtout pas en écriture.

**Conseils** : Penser aux méthodes d'accès.

___

**Correction**

Nous définissions deux méthodes d'accès, la première dénomée `upper()`, la seconde denomée `upper()` qui vont retourner
respectivement les valeurs des champs: `mUpperBound` et `mLowerBound`. Ces fonctions membres sont marquées comme constante
puisqu'elles ne modifient pas le contenu de l'objet.

___

```cpp
    int lower() const
    {
        return mLowerBound;
    }
    int upper() const
    {
        return mUpperBound;
    }
```
___


