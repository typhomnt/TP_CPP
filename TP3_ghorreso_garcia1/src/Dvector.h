#ifndef DVECTORH
#define DVECTORH
#include "Darray.h"

/**
 * @file Dvector.h
 *
 * Classe representant des vecteurs de double.
 */
class Dvector: public Darray {
	public:
		/**
		 * Constructeur par defaut
		 */
		Dvector();
		/**
		 * Constructeur initialisant la taille du vecteur et la valeur initiale qui
		 * vaut 0.0 par defaut
		 * @param dim est la dimension du vecteur
		 * @param val est la valeur par defaut des elements du vecteur
		 */
		Dvector(const int dim, const double val=0.0);
		/**
		 * Constructeur par copie
		 * @param d : vecteur qui va etre copie
		 */
		Dvector(const Dvector& d);
		/**
		 * Constructeur utilisant un fichier. Si le fichier n'existe pas, un
		 * vecteur de taille nulle est cree
		 * @param file : fichier donne en entree
		 */
		Dvector(const std::string file);
		/**
		 * Destructeur
		 */
		~Dvector();
		
	    /**
	     * Permet de visualiser (et manipuler) une sous-partie du vecteur de
	     * l'objet courant comme un vecteur a part entiere. L'attribut isProp
	     * de l'objet cree vaut alors true.
	     * @param copy : si copy==true, alors la methode recopie une par une les
	     * valeurs du vecteur; si copy==false, alors la methode fait coincider
	     * l'adresse du vecteur de l'objet resultant et l'adresse de l'element
	     * d'indice start du vecteur de l'objet courant
	     * @param start : premier indice du vecteur de l'objet courant a considerer
	     * @param count : nombre d'elements du sous-bloc cree
	     * @return true si l'objet donné en parametre a un vecteur de meme taille
	     * et avec les memes valeurs que celui de l'objet courant.
	     */
		Dvector view(bool copy, const int start, const int count) const;
};

/**
 * Calcule le produit scalaire canonique entre deux vecteurs.
 * Les deux vecteurs doivent etre de meme taille et differents de NULL.
 * @param d1 : premier Dvector
 * @param d2 : second Dvector
 * @return produit scalaire des deux vecteurs
 */
double operator*(const Dvector& d1, const Dvector& d2);
#endif
