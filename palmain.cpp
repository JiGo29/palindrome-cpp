#include "pfile.hpp" // On inclut le fichier contenat la structure de nos files
#include "ppile.hpp" // On fait pareil avec le fichier des piles

#include <iostream> // Pour la saisie et l'affichage à l'écran
#include <string> // Pour utiliser les chaines de caractères

using namespace std; // Armoire std, pour éviter de tout le temps faire std:: 

// En paramètre des passages par référence pour ne pas faire des copîes
void empiler(Pile<char> &a, const string &phrase) // Pour empiler dans la pile
{
    // on parcout la chaine de caractères caractère après caractère pour les mettre dans la pile
    for(auto mot : phrase)
    {
        // Si le caractère n'est pas une lettre de l'alphabet, on le saute et on passe au suivant
        if(!isalpha(mot)) continue;
        mot = tolower(mot);
        a.push(mot); // Si c'est une lettre de l'alphabet, on l'empile
    }
}

// En paramètre des passages par référence pour ne pas faire des copîes
void enfiler(File<char> &a, const string &phrase) // Pour enfiler dans la file
{
    // on parcout la chaine de caractères caractère après caractère pour les mettre dans la file
    for(auto mot : phrase)
    {
        // Si le caractère n'est pas une lettre de l'alphabet, on le saute et on passe au suivant
        if(!isalpha(mot)) continue;
        mot = tolower(mot);
        a.enqueue(mot); // Si c'est une lettre de l'alphabet, on l'enfile
    }
}

/* 
On vérifie si tous les éléments de la pile et la file sont identiques, élément après élément toute en faisant sûr que le nombre de
caractère verifié dans la pile et la file en même temps est égal

*/
bool estPalindrome(Pile<char>* a, File<char>* b) // On prend en paramètre des pointeurs vers les deux file et pile
{
    // Si la taille des deux tableaux est différente alors la chaine de caractère n'et pas un palindrome
    if(a->getTaille() != b->getTaille())
        return false;
    // Dans le cas contraire on compare les caractères en mode binome tant que leurs tailles respectives sont supérieures à 0
    while(a->getTaille() != 0 || b->getTaille() != 0)
    {
        // Si en comparant les deux caractères, alors ce n'est pas un palindrome
        if(a->pvaleur() != b->fvaleur())
            return false;
        // Si ils sont pareils alors on continue en faisant respectivement le dépilement du caractère dans la pile et le défilement du caractère dans la file
        a->pop(); // dans la file
        b->dequeue(); //dans la file
    }
    return true; // Si après comparaison leurs tailles sont égales te aucun élément n'est différent de l'autre, on return true qui veut dire que c'est un palindrome
}

int main()
{
    Pile<char> pileA; // On crée une pile
    File<char> fileA; // On crée une file

    string palindrome; // La chaine de caractère est stockée dans une variable de type string
    cout<<"Tapez le mot ou la phrase à vérifier: "<<endl;
    while(getline(cin, palindrome)) // Tant qu'on fait une saisie d'une phraseà l'écran ligne par ligne
	{
		empiler(pileA, palindrome); // On va empile la phrase caractère après caractère
		enfiler(fileA, palindrome); // On enfile la phrase caractère après caractère

		cout << (estPalindrome(&pileA, &fileA) ? "C'est un palindrome" : "Ce n'est pas un palindrome") << '\n'; // On vérifie si c'est un palindrome

		pileA.pclear(); // On vide la pile
		fileA.fclear(); // On vide la file
	}
    return 0;
}


// Fin du programme
