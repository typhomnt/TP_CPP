#ifndef DARRAYH
#define DARRAYH
#include <iostream>
#include <istream>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @file Darray.h
 *
 * Classe representant les tableaux
 */

class Darray {
 protected:
	/**
	 * Taille du Darray
	 */
	int sizeD;
	/**
	 * Tableau associe au Darray
	 */
	double *data;
	/**
	 * Attribut permettant de savoir si l’instance de la classe est
	 * propriétaire ou non de son pointeur de données. Il vaut true
	 * pour tous les objets crees sans la fonction view
	 */
	bool isProp;

 public:
	/**
	 * Constructeur par defaut
	 */
	Darray();
	/**
	 * Constructeur initialisant la taille du Darray et la valeur initiale qui
	 * vaut 0.0 par defaut
	 * @param dim est la dimension du Darray
	 * @param val est la valeur par defaut des elements du Darray
	 */
	Darray(const int dim, const double val=0.0);
	/**
	 * Constructeur par copie
	 * @param d : Darray qui va etre copie
	 */
	Darray(const Darray& d);
	/**
	 * Constructeur utilisant un fichier. Si le fichier n'existe pas, un
	 * Darray de taille nulle est cree
	 * @param file : fichier donne en entree
	 */
	Darray(const std::string file);
	/**
	 * Destructeur
	 */
	~Darray();
	/**
	 * @return taille du Darray
	 */
	int size() const;
	/**
	 * @return tableau associe au Darray
	 */
	const double* getData() const;
	/**
	 * @return valeur de l'attribut isProp
	 */
	bool isOwner() const;
	/**
	 * Methode permettant d'afficher les differentes composantes du Darray
	 * sur un flux de sortie
	 * @param str : flux de sortie
	 */
	void display(std::ostream& str) const;
	/**
	 * Associe a chaque element du tableau, une valeur aleatoire comprise
	 * entre 0 et 1
	 */
	void fillRandomly();
	/**
	 * Operateur permettant d'acceder a la valeur d'indice i du Darray.
	 * Elle renvoie une erreur si i < 0 ou i > size-1 où size est la taille du
	 * Darray
	 * @param i : indice du Darray
	 * @return reference vers la valeur d'indice i du Darray
	 */
	double& operator()(const int i) const;
	/**
	 * Permet de visualiser (et manipuler) une sous-partie du Darray de
	 * l'objet courant comme un Darray a part entiere. L'attribut isProp
	 * de l'objet cree vaut alors true.
	 * @param copy : si copy==true, alors la methode recopie une par une les
	 * valeurs du Darray; si copy==false, alors la methode fait coincider
	 * l'adresse du Darray de l'objet resultant et l'adresse de l'element
	 * d'indice start du Darray de l'objet courant
	 * @param start : premier indice du Darray de l'objet courant a considerer
	 * @param count : nombre d'elements du sous-bloc cree
	 * @return true si l'objet donné en parametre a un Darray de meme taille
	 * et avec les memes valeurs que celui de l'objet courant.
	 */
	Darray view(bool copy, const int start, const int count) const;
		 
	/**
	 * Operateur permettant d'affecter les attributs de l'objet donné en
	 * parametre a l'objet courant. Dans la suite, P signifie que le
	 * Darray est proprietaire de ses donnees, NP que le Darray n’est
	 * pas proprietaire de ses données, Err signifie que l’operation leve
	 * une exception et 0 signifie que le Darray n’a pas ete initialise
	 * (Darray de taille 0). On distingue les cas suivants pour connaitre
	 * la valeur de l'attribut isProp de l'objet a, lorsqu'on fait
	 * l'operation a = b (on met dans l'ordre, l'état de a, de b puis de a
	 * apres affectation)
	 *
	 * 1er cas : a et b sont de meme taille
	 * 		- cas 1 : P et P => P
	 * 		- cas 2 : P et NP => P
	 * 		- cas 3 : NP et P => NP
	 * 		- cas 4 : NP et NP => NP
	 * 		- cas 5 : 0 et P => P
	 * 		- cas 6 : 0 et NP => NP
	 *
	 * 2e cas : a et b sont de taille differente
	 *  	- cas 1 : P et P => P
	 *  	- cas 2 : P et NP => P
	 *  	- cas 3 : NP et P => Err
	 *  	- cas 4 : NP et NP => Err
	 *  	- cas 5 : 0 et P => P
	 *  	- cas 6 : 0 et NP => NP
	 * @param d : reference vers l'objet
	 * @return reference vers l'objet avec les nouveaux attributs
	 */
	Darray& operator=(const Darray& d);
	/**
	 * Operateur permettant d'ajouter la valeur r a toutes les valeurs du Darray
	 * @param r : double constant a ajouter
	 * @return reference vers l'objet avec le nouveau Darray
	 */
	Darray& operator+=(const double r);
	/**
	 * Operateur permettant de soustraire la valeur r a
	 * toutes les valeurs du Darray
	 * @param r : double constant a soustraire
	 * @return reference vers l'objet avec le nouveau Darray
	 */
	Darray& operator-=(const double r);
	/**
	 * Operateur permettant de multiplier toutes les valeurs du Darray
	 * par la valeur r
	 * @param r : double constant
	 * @return reference vers l'objet avec le nouveau Darray
	 */
	Darray& operator*=(const double r);
	/**
	 * Operateur permettant de diviser toutes les valeurs du Darray
	 * par la valeur r, qui doit etre non nulle
	 * @param r : double constant
	 * @return reference vers l'objet avec le nouveau Darray
	 */
	Darray& operator/=(const double r);
		
		
	/**
	 * Operateur permettant d'ajouter le Darray d'un autre objet terme a terme.
	 * Le nouveau Darray doit etre de meme taille que celui de l'objet.
	 * @param d : reference vers l'objet
	 * @return reference vers l'objet avec le nouveau Darray
	 */
	Darray& operator+=(const Darray& d);
	/**
	 * Operateur permettant de soustraire le Darray d'un autre
	 * objet terme a terme. Le nouveau Darray doit etre de meme
	 * taille que celui de l'objet.
	 * @param d : reference vers l'objet
	 * @return reference vers l'objet avec le nouveau Darray
	 */
	Darray& operator-=(const Darray& d);
	/**
	 * Teste l'egalite entre deux Darray.
	 * @param d : reference vers l'objet
	 * @return true si l'objet donné en parametre a un Darray de meme taille
	 * et avec les memes valeurs que celui de l'objet courant.
	 */
	bool operator==(const Darray& d) const;
		
	/**
	 * Teste l'inegalite entre deux Darray.
	 * @param d : reference vers l'objet
	 * @return true si l'objet donné en parametre a un Darray de taille
	 * differente ou avec des valeurs differentes que celui de l'objet courant.
	 */
	bool operator!=(const Darray& d) const;
};
/**
 * Addition d'un Darray et d'un double r. On ajoute r a chaque valeur
 * du Darray.
 * @param d : référence constante du Darray a gauche
 * @param r : double constante
 * @return le Darray resultant
 */
Darray operator+(const Darray& d, const double r);
/**
 * Soustraction d'un Darray et d'un double r. On ajoute r a chaque valeur
 * du Darray.
 * @param d : référence constante du Darray a gauche
 * @param r : double constante
 * @return le Darray resultant
 */
Darray operator-(const Darray& d, const double r);
/**
 * Multiplication d'un Darray et d'un double r. On ajoute r a chaque valeur
 * du Darray.
 * @param d : référence constante du Darray a gauche
 * @param r : double constante
 * @return le Darray resultant
 */
Darray operator*(const Darray& d, const double r);
/**
 * Division d'un Darray et d'un double r. On ajoute r a chaque valeur
 * du Darray.
 * @param d : référence constante du Darray a gauche
 * @param r : double constante
 * @return le Darray resultant
 */
Darray operator/(const Darray& d, const double r);
/**
 * Addition d'un double r et d'un Darray. On ajoute r a
 * chaque valeur du Darray.
 * @param r : double constante
 * @param d : référence constante du Darray a droite
 * @return le dvector resultant
 */
Darray operator+(const double r, const Darray& d);
/**
 * Multiplication d'un double r et d'un Darray. On ajoute r a
 * chaque valeur du Darray.
 * @param r : double constante
 * @param d : référence constante du Darray a droite
 * @return le dvector resultant
 */
Darray operator*(const double r, const Darray& d);

/**
 * Addition de deux Darray. Les deux Darray doivent etre de meme taille.
 * @param d1 : référence constante du Darray a gauche
 * @param d2 : référence constante du Darray a droite
 * @return le Darray resultant
 */
Darray operator+(const Darray& d1, const Darray& d2);
/**
 * Soustraction de deux Darray. Les deux Darray doivent etre de meme taille.
 * @param d1 : référence constante du Darray a gauche
 * @param d2 : référence constante du Darray a droite
 * @return le Darray resultant
 */
Darray operator-(const Darray& d1, const Darray& d2);
/**
 * Oppose d'un Darray. On prend l'oppose de chaque valeur du Darray.
 * @param d : référence constante au Darray
 * @return le Darray resultant
 */
Darray operator-(const Darray& d);
#endif
