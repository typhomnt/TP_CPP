#ifndef DVECTORH
#define DVECTORH
#include "Darray.h"

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
};

double operator*(const Dvector& d1, const Dvector& d2);
#endif
