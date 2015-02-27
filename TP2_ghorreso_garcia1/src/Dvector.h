#ifndef DVECTORH
#define DVECTORH
#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class Dvector{
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
     * Methode permettant d'afficher les differentes composantes du vecteur
     * sur un flux de sortie
     * @param str : flux de sortie
     */
    void display(std::ostream& str) const;

    /**
     * Methode permettant de stocker les valeurs du vecteur de l'objet dans un
     * flux d'entree
     * @param str : flux d'entree dans lequel les valeurs sont stockées
     */
    void enter(std::istream& str);
    /**
     * @return tableau associe au vecteur
     */
    const double* getData() const;
    /**
     * @return taille du vecteur
     */
    int size() const;
    /**
     * Associe a chaque element du tableau, une valeur aleatoire comprise
     * entre 0 et 1
     */
    void fillRandomly();

    /**
     * @return valeur de l'attribut isProp
     */
    bool isOwner() const;

    /**
     * Operateur permettant d'acceder a la valeur d'indice i du vecteur.
     * Elle renvoie une erreur si i < 0 ou i > size-1 où size est la taille du
     * vecteur
     * @param i : indice du vecteur
     * @return reference vers la valeur d'indice i du vecteur
     */
    double& operator()(const int i) const ;

    /**
     * Operateur permettant d'ajouter la valeur r a toutes les valeurs du vecteur
     * @param r : double constant a ajouter
     * @return reference vers l'objet avec le nouveau vecteur
     */
    Dvector& operator+=(const double r);

    /**
     * Operateur permettant de soustraire la valeur r a
     * toutes les valeurs du vecteur
     * @param r : double constant a soustraire
     * @return reference vers l'objet avec le nouveau vecteur
     */
    Dvector& operator-=(const double r);

    /**
     * Operateur permettant de multiplier toutes les valeurs du vecteur
     * par la valeur r
     * @param r : double constant
     * @return reference vers l'objet avec le nouveau vecteur
     */
    Dvector& operator*=(const double r);

    /**
     * Operateur permettant de diviser toutes les valeurs du vecteur
     * par la valeur r, qui doit etre non nulle
     * @param r : double constant
     * @return reference vers l'objet avec le nouveau vecteur
     */
    Dvector& operator/=(const double r);

    /**
     * Operateur permettant d'ajouter le vecteur d'un autre objet terme a terme.
     * Le nouveau vecteur doit etre de meme taille que celui de l'objet.
     * @param d : reference vers l'objet
     * @return reference vers l'objet avec le nouveau vecteur
     */
    Dvector& operator+=(const Dvector& d);

    /**
     * Operateur permettant de soustraire le vecteur d'un autre
     * objet terme a terme. Le nouveau vecteur doit etre de meme
     * taille que celui de l'objet.
     * @param d : reference vers l'objet
     * @return reference vers l'objet avec le nouveau vecteur
     */
    Dvector& operator-=(const Dvector& d);
    
    /**
     * Operateur permettant d'affecter les attributs de l'objet donné en
     * parametre a l'objet courant. Dans la suite, P signifie que le
     * vecteur est proprietaire de ses donnees, NP que le vecteur n’est
     * pas proprietaire de ses données, Err signifie que l’operation leve
     * une exception et 0 signifie que le vecteur n’a pas ete initialise
     * (vecteur de taille 0). On distingue les cas suivants pour connaitre
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
    Dvector& operator=(const Dvector& d);

    /**
     * Teste l'egalite entre deux Dvector.
     * @param d : reference vers l'objet
     * @return true si l'objet donné en parametre a un vecteur de meme taille
     * et avec les memes valeurs que celui de l'objet courant.
     */
    bool operator==(const Dvector& d) const;

    /**
     * Teste l'inegalite entre deux Dvector.
     * @param d : reference vers l'objet
     * @return true si l'objet donné en parametre a un vecteur de taille
     * differente ou avec des valeurs differentes que celui de l'objet courant.
     */
    bool operator!=(const Dvector& d) const;

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


 private:
    /**
     * Taille du vecteur
     */
    int sizeV;
    /**
     * Tableau associe au vecteur
     */
    double *vect;
    /**
     * Attribut permettant de savoir si l’instance de la classe est
     * propriétaire ou non de son pointeur de données. Il vaut true
     * pour tous les objets crees sans la fonction view
     */
    bool isProp;
};

/**
 * Addition de deux Dvector. Les deux vecteurs doivent etre de meme taille.
 * @param d1 : référence constante du Dvector a gauche
 * @param d2 : référence constante du Dvector a droite
 * @return le dvector resultant
 */
Dvector operator+(const Dvector& d1, const Dvector& d2);

/**
 * Soustraction de deux Dvector. Les deux vecteurs doivent etre de meme taille.
 * @param d1 : référence constante du Dvector a gauche
 * @param d2 : référence constante du Dvector a droite
 * @return le dvector resultant
 */
Dvector operator-(const Dvector& d1, const Dvector& d2);

/**
 * Addition d'un Dvector et d'un double r. On ajoute r a chaque valeur
 * du vecteur.
 * @param d : référence constante du Dvector a gauche
 * @param r : double constante
 * @return le dvector resultant
 */
Dvector operator+(const Dvector& d, const double r);

/**
 * Soustraction d'un Dvector et d'un double r. On soustrait r a
 * chaque valeur du vecteur.
 * @param d : référence constante du Dvector a gauche
 * @param r : double constante
 * @return le dvector resultant
 */
Dvector operator-(const Dvector& d, const double r);

/**
 * Multiplication d'un Dvector et d'un double r. On multiplie par r
 * chaque valeur du vecteur.
 * @param d : référence constante du Dvector a gauche
 * @param r : double constante
 * @return le dvector resultant
 */
Dvector operator*(const Dvector& d, const double r);

/**
 * Division d'un Dvector et d'un double r. On divise par r
 * chaque valeur du vecteur.
 * @param d : référence constante du Dvector a gauche
 * @param r : double constante
 * @return le dvector resultant
 */
Dvector operator/(const Dvector& d, const double r);

/**
 * Addition d'un double r et d'un Dvector. On ajoute r a
 * chaque valeur du vecteur.
 * @param r : double constante
 * @param d : référence constante du Dvector a droite
 * @return le dvector resultant
 */
Dvector operator+(const double r, const Dvector& d);

/**
 * Multiplication d'un double r et d'un Dvector. On multiplie par r
 * chaque valeur du vecteur.
 * @param r : double constante
 * @param d : référence constante du Dvector a droite
 * @return le dvector resultant
 */
Dvector operator*(const double r, const Dvector& d);

/**
 * Oppose d'un Dvector. On prend l'oppose de chaque valeur du vecteur.
 * @param d : référence constante au Dvector
 * @return le dvector resultant
 */
Dvector operator-(const Dvector& d);

/**
 * Operateur de flux de sortie. Les valeurs du vecteur sont stockees
 * dans le flux de sortie.
 * @param out : reference du flux de sortie
 * @param d : reference du Dvector
 * @return reference du flux de sortie resultant
 */
std::ostream& operator<<(std::ostream& out, const Dvector& d);

/**
 * Operateur de flux d'entree. Les valeurs du vecteur sont stockees
 * dans le flux d'entree.
 * @param out : reference du flux d'entree
 * @param d : reference du Dvector
 * @return reference du flux d'entree resultant
 */
std::istream& operator>>(std::istream& in, Dvector& d);

#endif
