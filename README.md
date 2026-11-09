# Vérificateur de palindromes avec une pile et une file

Programme en C++ qui détermine si un mot ou une phrase est un **palindrome**, c'est-à-dire qu'il se lit de la même façon de gauche à droite et de droite à gauche (`radar`, `Kayak`, `Engage le jeu que je le gagne`).

Le projet repose sur deux structures de données **génériques codées à la main** avec des noeuds chaînés : une **pile** (LIFO) et une **file** (FIFO). Il n'utilise ni `std::stack` ni `std::queue`.

## Principe

Une pile retourne l'ordre des éléments, alors qu'une file le conserve. Pour vérifier un palindrome :

1. Chaque lettre de la phrase est mise dans la **pile** et dans la **file**.
2. On retire ensuite les éléments un à un : la pile donne les lettres **de la fin vers le début**, la file donne les lettres **du début vers la fin**.
3. Si une paire de lettres est différente, ce n'est pas un palindrome. Si toutes les paires sont identiques, c'en est un.

Avant la comparaison, les caractères qui ne sont pas des lettres (espaces, ponctuation, chiffres) sont ignorés et les lettres sont converties en minuscules. Ainsi, `A man, a plan, a canal: Panama` est reconnu comme un palindrome.

## Fonctionnalités

- Pile générique `Pile<A>` : `push`, `pop`, `pvaleur`, `getTaille`, `pclear`
- File générique `File<A>` : `enqueue`, `dequeue`, `fvaleur`, `getTaille`, `fclear`
- Noeud générique `Noeud<A>` partagé par les deux structures
- Insensible à la casse, aux espaces et à la ponctuation
- Libération de la mémoire dans les destructeurs
- Plusieurs vérifications à la suite, une par ligne saisie

## Structure du projet

| Fichier        | Rôle                                                                          |
|----------------|-------------------------------------------------------------------------------|
| `noeud.hpp`    | Classe `Noeud<A>` : une valeur et un pointeur vers le noeud suivant           |
| `ppile.hpp`    | Classe `Pile<A>` implémentée avec une liste chaînée                           |
| `pfile.hpp`    | Classe `File<A>` implémentée avec une liste chaînée                           |
| `palmain.cpp`  | Programme principal : saisie, remplissage de la pile et de la file, vérification |

Les fonctions principales de `palmain.cpp` sont :
- `empiler()` : parcourt la phrase, garde les lettres en minuscules et les empile
- `enfiler()` : fait la même chose avec la file
- `estPalindrome()` : compare les tailles, puis compare le sommet de la pile avec le début de la file, en retirant un élément de chacune à chaque tour

## Compilation et exécution

Un compilateur C++ (g++, clang++ ou MSVC) est requis. Les quatre fichiers doivent être dans le même dossier.

```bash
g++ -Wall -Wextra -o palmain palmain.cpp
./palmain
```

Sous Windows :

```bash
g++ -Wall -Wextra -o palmain.exe palmain.cpp
palmain.exe
```

## Utilisation

Tapez un mot ou une phrase, puis appuyez sur Entrée. Le programme répond, puis attend la prochaine saisie. Pour quitter, terminez l'entrée avec Ctrl+D (Ctrl+Z puis Entrée sous Windows).

```
Tapez le mot ou la phrase à vérifier:
radar
C'est un palindrome
Engage le jeu que je le gagne
C'est un palindrome
A man, a plan, a canal: Panama
C'est un palindrome
bonjour
Ce n'est pas un palindrome
```

## Limites connues

- Les **lettres accentuées ne sont pas gérées** : elles sont ignorées. Par exemple, `été` est lu comme `t` et `école` comme `cole`.
- Une saisie **vide** (ou sans aucune lettre) est considérée comme un palindrome.
- Les classes sont génériques (`template <typename A>`), mais `push` et `enqueue` prennent un `char` en paramètre : elles ne fonctionnent donc qu'avec des caractères pour l'instant.
- `enqueue` parcourt toute la file pour ajouter à la fin, car la file ne garde pas de pointeur vers son dernier noeud. Son coût est donc proportionnel à la taille de la file.
- `pop` sur une pile vide retourne `-1` au lieu de signaler une erreur.

## Pistes d'amélioration

- Ajouter un pointeur vers le dernier noeud de la file pour que `enqueue` soit en temps constant
- Remplacer `const char &` par `const A &` dans `push` et `enqueue` pour que les classes soient vraiment génériques
- Gérer les lettres accentuées (par exemple avec `<locale>` ou en retirant les accents avant la comparaison)
- Comparer seulement la première moitié de la phrase pour réduire le nombre d'opérations
- Séparer la déclaration et l'implémentation des classes et ajouter des tests automatisés

## Auteur

Jonathan Balezi, étudiant au baccalauréat en informatique appliquée (régime coop) à l'Université de Moncton.

- Portfolio : https://jigo29.github.io/portfolio/
- GitHub : https://github.com/JiGo29
- LinkedIn : https://www.linkedin.com/in/balezi-jonathan-a991a6386/
