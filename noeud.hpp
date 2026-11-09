#pragma once // Pour include une seule fois ce fichier lors de la compilation

// Type générique de tous les noeuds
template <typename A> class Noeud
{
	public:
		A element;		// valeur du noeud
		Noeud* suivant;	// pointeur vers le noeud suivant

		// Constructeurs
		Noeud(const A &val) : element(val), suivant(nullptr) {}
		//Noeud(Noeud *suiv = nullptr) : next(suiv) {}
};