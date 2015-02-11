#ifndef DVECTORH
#define DVECTORH
#include <iostream>
#include <fstream>
#include <stdlib.h>

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
    void display(std::ostream& str);
    /**
     * @return tableau associe au vecteur
     */
    double* getVect();
    /**
     * @return taille du vecteur
     */
    int size();
    /**
     * Associe a chaque element du tableau, une valeur aleatoire comprise
     * entre 0 et 1
     */
    void fillRandomly();

    double& operator()(int i);

    void  operator+=(double r);

    void  operator-=(double r);

    void  operator*=(double r);

    void  operator/=(double r);

    Dvector operator+(const Dvector& d);

    void operator=(const Dvector& d);
 private:
    /**
     * Taille du vecteur
     */
    int sizeV;
    /**
     * Tableau associe au vecteur
     */
    double *vect;
};

#endif
