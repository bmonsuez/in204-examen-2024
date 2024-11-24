### Question 2. Les intervals "vides" [Correction]

Nous avons un souci avec les intervals "vides". Un interval est dit vide si quand on passe les paramètres `lowerBound` et `upperBound`, `upperBound` est plus petit que `lowerBound`.

### Question 2.1 Les intervals "vides"

Proposer une fonction  membre `bool empty() const` qui teste si l'interval est vide ou n'est pas vide.

___

**Correction**:

```cpp
    bool empty() const
    {
        return mUpperBound < mLowerBound;
    }
```

Comme l'interval vide est défini par `mLowerBound`$=0$ et `mUpperBound`$=-1$ et que dans les autres cas 
`mLowerBound`$<>=$`mUpperBound`$=-1$, il suffit de tester si `mUpperBound` est plus petit que `mLowerBound`.

___

### Question 2.2 Les intervals "vides"

Pourquoi la fonction le mot clé `const` suit la définition de la fonction `bool empty()` ?

___

**Correction**:
Le mot clé `const` qui suit la définition de d'une fonction membre indique que la fonction membre ne modifie aucun des 
champs de l'objet et n'appelle aucune fonction membre qui ne serait pas marquée comme  `const` constante et donc 
qui pourrait modifier un des champs de l'objet.

___
