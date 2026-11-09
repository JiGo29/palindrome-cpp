#include "noeud.hpp" // Nous allons utiliser la structure du noeud pour notre pile 
#include <cassert> // Pour vérifier les conditions

template <typename A> class Pile // Une pile de type générique
{
    private:
    // Chaque element est donc un noeud qui contient un élément et un pointeur vers le prochain élément
    Noeud<A>* sommet;
    int taille; // Taille de la pile
 
    public:
// Constructeur de la pile
    Pile() : sommet(nullptr), taille(0) {}

    void push(const char &mot) // Ajouter un élément au sommet de la pile
    {
        Noeud<A>* nouveau = new Noeud<A>(mot); // On met le nouveau élément dans un noeud
        nouveau->suivant = sommet; // Le pointeur du nouvel élément pointe su rle même élément qu ele pointeur du sommet
        sommet = nouveau; // Le sommet pointe vers le nouvel élément finalement

        taille++; // On incréménte la taille de la pile
    }
    // La fonction est de type A, notre type que nous avons créé vu qu'elle pourra prendre n'importe quel type de variable en retour (float, int, double, char, ...)
    A pop() // Enlever l'élément au somment de la pile
    {
        if(sommet == nullptr) // Si la pile est vide, le pointeur pointe vers rien
            return -1; // On sort de la fonction, vu qu'elle est vide
        Noeud<A>* asupprimer = sommet; // On enregistre l'élément à supprimer dans un noeud 
        char mot = asupprimer->element; // La valeur de l'élément à supprimer est enregistré pour être affichée
        sommet = asupprimer->suivant; // Le sommet pointe vers le prochain élément qui est pointé par l'élément suppprimé
        delete asupprimer; // Suppression de l'élément en toute sécurité
        taille--; // La taille décrémente de 1

        return mot; // On retourne le mot
    }

    int getTaille() const 
    { 
        return taille; // Pour avoir accès à la taille de la pile en toute sécurité en dehors de la classe
    }

    A pvaleur()
    {
        // assert nous permet de faire un return si la condition est remplie
        assert(taille != 0 && "Pile vide"); // Si la pile est vide, on ne peut pas afficher la valeur de l'élément qui est au sommet

        return sommet->element; // Si la pile n'est pas vide, on retourne la valeur de l'élément qui est au sommet
    }
    
    // Supprimer la pile s'il y a des éléments restants (dans le cas où ce n'est pas un palindrome)
    void pclear()
    {
        if(sommet == nullptr) // Si la pile est vide, pas d'action recquise
            return;
        // Dans le cas contraire, on parcourt la pile noeud après noeud pour la vider, tant que le sommet ne pointe pas vers nullptr
        while(sommet != nullptr && taille != 0) 
        {
            Noeud<A>* temp = sommet;
            sommet = temp->suivant;
            delete temp;
            temp = nullptr;
        }
        // Par sécurité, on fait sommet !! nullptr et la taille à zéro
        sommet = nullptr;
        taille = 0;
    }

    // Destructeur qui permet de vider complétement la pile et mettre le pointeur de la pile à nullptr et la taille à 0
    ~Pile()
    {
        pclear();
    }
};