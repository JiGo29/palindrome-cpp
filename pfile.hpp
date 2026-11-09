#include "noeud.hpp" // Nous allons utiliser la structure du noeud pour notre pile 
#include <cassert> // Pour vérifier les conditions

template <typename A> class File // Une file de type générique
{
    private :
    // Chaque element est donc un noeud qui contient un élément et un pointeur vers l'élément devant lui
    Noeud<A>* arriere;
    int taille; // Taille de la pile

    public:
    // Constructeiur de la file
    File() : arriere(nullptr), taille (0) {}

    void enqueue(const char &mot) // Ajouter un élément au débutfin de la file
    {
        Noeud<A>* nouveau = new Noeud<A>(mot); // On enregistre le nouvel élément dans un noeud
        if(arriere == nullptr) // Si la file est vide
        {
            arriere = nouveau; // Le pointeur de la file pointe directement sur le nouvel élément
            taille++; // On incréménte la taille de la file

            return; // Pas besoin de continuer les autres opérations de cette fonction
        }
        Noeud<A>* temp = arriere; // Dans le cas o la file a déja des éléments on crée un noeud temporaire qui pointe sur l" pointeur de la file
        while(temp->suivant != nullptr) // Tant que le prochain élément ne pointe pas ne pointe pas vers rien
        {
            temp = temp->suivant; // On parcourt la file jusqu'au dervier élément
        }
        temp->suivant = nouveau; // Si le dernier élément pointe vers rien du tout alors, il va pointer vers le nouvel élément

        taille++; // On incrémente la taille de la file
    }

    A dequeue() // Enlever le premier élément à avoir été enregistré
    {
        assert(taille != 0 && "File vide"); // Si la file est vide, on ne peut rien retirer

        A mot = arriere->element; // On enregistre la valeur du noeud qu'on va supprimer
        Noeud<A>* temp = arriere; // On enregistre l'éléme,nt dans un noeud temporaire
        arriere = temp->suivant; // Le pointeur de la file pointe donc vers le prochain élément pointée par l'élément temporaire
        delete temp; // On supprime l'élément à supprimer
        temp = nullptr; // Sécurité du pointeur vers nullptr
        taille--; // On décrémente la taille de la file
        return mot; // On affiche la valeur de l'élément qui a été supprimé

    }

    int getTaille()
    {
        return taille; // Pour avoir accès à la taille de la file en toute sécurité en dehors de la classe
    }

    A fvaleur()
    {
        // assert nous permet de faire un return si la condition est remplie
        assert(taille != 0 && "File vide");
        
        return arriere->element; // Si la pile n'est pas vide, on retourne la valeur de l'élément
    }

    // Supprimer la file s'il y a des éléments restants (dans le cas où ce n'est pas un palindrome)
    void fclear()
    {
        if(arriere == nullptr) // Si la pile est vide, pas d'action recquise
            return;
        // Dans le cas contraire, on parcourt la file noeud après noeud pour la vider, tant que le sommet ne pointe pas vers nullptr
        while(arriere != nullptr && taille != 0)
        {
            Noeud<A>* temp = arriere;
            arriere = temp->suivant;
            delete temp;
            temp = nullptr;
        }
        // Par sécurité, on fait sommet !! nullptr et la taille à zéro
        arriere = nullptr;
        taille = 0;
    }

    // Destructeur qui permet de vider complétement la file et mettre le pointeur de la file à nullptr et la taille à 0
    ~File()
    {
        fclear();
    }
};