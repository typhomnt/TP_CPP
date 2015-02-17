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
    Dvector(int dim, double val=0.0);
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
    Dvector(std::string file);
    /**
     * Destructeur
     */
    ~Dvector();
    /**
     * Methode permettant d'afficher les differentes composantes du vecteur
     * sur un flux d'entree
     * @param str : flux d'entree
     */
    void display(std::ostream& str) const;

    void enter(std::istream& str) const;
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

    bool isOwner() const;

    double& operator()(int i);

    Dvector& operator+=(double r);

    Dvector& operator-=(double r);

    Dvector& operator*=(double r);

    Dvector& operator/=(double r);

    Dvector& operator+=(const Dvector& d);

    Dvector& operator-=(const Dvector& d);
    
    Dvector& operator=(const Dvector& d);

    bool operator==(const Dvector& d);

    bool operator!=(const Dvector& d);

    Dvector view(bool copy, int start, int count);


 private:
    /**
     * Taille du vecteur
     */
    int sizeV;
    /**
     * Tableau associe au vecteur
     */
    double *vect;
    
    bool isProp;
};

Dvector operator+(const Dvector& d1, const Dvector& d2);

Dvector operator-(const Dvector& d1, const Dvector& d2);

Dvector operator+(double &r, const Dvector& d);

Dvector operator-(double &r, const Dvector& d);

Dvector operator*(double &r, const Dvector& d);

Dvector operator/(double &r, const Dvector& d);

Dvector operator-(const Dvector& d);

std::ostream& operator<<(std::ostream& out, const Dvector& d);

std::istream& operator>>(std::istream& in, const Dvector& d);

#endif
