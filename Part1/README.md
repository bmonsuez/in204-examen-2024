## Partie n°1: Définition d'une classe **interval** d'entiers  [Correction]

Nous considérons dans un premier temps le squelette de classe suivant :

```cpp
#include<vector>

class interval
{
private:
    int mLowerBound;               // Index de la première valeur de la vue.
    int mUpperBound;               // Index de la dernière valeur de la vue.

public:
    interval();
    interval(int lowerBound, int upperBound);
};
```

Nous considérons que si l'interval n'est pas vide, la propriété: `mLowerBound`$<=$`mUpperBound` doit toujours être vérifiée. Si l'interval est vide, alors `mLowerBound`$=0$ et `mUpperBound`$=-1$. 


### 1. Les constructeurs

### Question 1.1

Expliquer à quoi correspondent les déclarations suivantes :

```cpp
    interval();
    interval(int lowerBound, int upperBound);
```
___

**Correction**:

```cpp
    interval();
```

Ce constructeur crée un interval par défaut. Un interval par défaut est a priori un interval vide.
 
```cpp
    interval(int lowerBound, int upperBound);
```

Ce constructeur crée un interval dont le premier élément est `lowerBound` et le dernier élément `upperBound`.

___

### Question 1.2

Pour chacun des constructeurs précédents, compléter le code des constructeurs.

**Remarque** : Le code est minimaliste, on ne demande pas de vérifier si les paramètres `lowerBound` et `upperBound` désignent des bornes.

___
**Correction**:

```cpp
     interval(): mLowerBound(0), mUpperBound(-1)
     {}
```

Comme le constructeur par défaut construit un interval vide, les champs `mLowerBound` et `mUpperBound` prennent les valeurs respectives $0$ et $-1$ pour indiquer que l'interval est vide.

```cpp
    interval(int lowerBound, int upperBound): mLowerBound(lowerBound), mUpperBound(upperBound)
    {}
```

Les champs `mLowerBound` et `mUpperBound` sont initialisés avec les bornes `lowerBound` et `upperBound`. Aucune vérification n'est faite pour s'assurer que  `lowerBound` est inférieur ou égal à `upperBound`. L'interval peut-être inconsistent.
___

### Question 1.3

Y aurait-il besoin de compléter la liste des constructeurs. Expliquer pourquoi c'est nécessaire ou ce n'est pas nécessaire.

Si vous ajoutez un ou plusieurs constructeurs, écrivez le constructeur et son code.

**Remarque** : Penser à un interval qui ne représente qu'un seul élément par exemple.

___

**Correction**:

En fait, le constructeur de recopie par défaut fonctionne parfaitement, il n'est pas besoin de définir un constructeur de recopie spécifique.
Cependant, à partir de C++11, il est possible d'indiquer que nous souhaitons explicitement utiliser le constructeur généré par défaut, pour ce faire, nous pouvons écrire :

```cpp
    interval(const interval&) = default; 
```

Ceci est utile pour documenter le fait que nous utilisons le constructeur de recopie par défaut. Si par contre, nous souhaitons interdire la copie pour un objet `non_copiable_object`, il est possible à partir de C++11 d'écrire :

```cpp
class non_copiable_object:
    non_copiable_object(const non_copiable_object&) = delete;
```

Cependant, nous pouvons imaginer un constructeur qui prend une valeur entière qui représente à la fois la borne inférieure et la borne supérieure de l'interval:

```cpp
    explicit interval(int theLowerAndUpperBound):
        mLowerBound(theLowerAndUpperBound), mUpperBound(theLowerAndUpperBound)
    {}
```

Le mot clé `explicit` est mis devant le constructeur pour empêcher le compilateur de créer automatiquement un interval à partir d'une valeur entière.

***Remarque :***
Nous pouvons constater que le constructeur :

```cpp
    explicit interval(int theLowerAndUpperBound):
        mLowerBound(theLowerAndUpperBound), mUpperBound(theLowerAndUpperBound)
        {}
```

est un cas particulier du constructeur :

```cpp
    interval(int lowerBound, int upperBound): 
        mLowerBound(lowerBound), mUpperBound(upperBound)
        {}
```

Dans ce cas, il est possible de définir le premier constructeur en faisant un appel au deuxième constructeur :

```cpp
    explicit interval(int theLowerAndUpperBound):
        interval(theLowerAndUpperBound, theLowerAndUpperBound)
        {}
    interval(int lowerBound, int upperBound): 
        mLowerBound(lowerBound), mUpperBound(upperBound)
        {}
```
___