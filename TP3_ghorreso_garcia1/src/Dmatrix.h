#ifndef DMATRIXH
#define DMATRIXH
#include "Darray.h"

class Dmatrix: public Darray {
	private:
		/*
		 * nombre de lignes de la matrice
		 */
		int m;
		/*
		 * nombre de colonnes de la matrice
		 */
		int n;
	public:
		/**
		 * Constructeur par defaut
		 */
		Dmatrix();
		/**
		 * Constructeur initialisant la taille de la matrice et la valeur initiale qui
		 * vaut 0.0 par defaut
		 * @param nbLignes est le nombre de lignes de la matrice
		 * @param nbColonnes est le nombre de colonnes de la matrice
		 * @param val est la valeur par defaut des elements de la matrice
		 */
		Dmatrix(const int nbLignes, const int nbColonnes, const double val=0.0);
		/**
		 * Constructeur par copie
		 * @param m : matrice qui va etre copie
		 */
		Dmatrix(const Dmatrix& mat);
		/**
		 * Destructeur
		 */
		~Dmatrix();

		double& operator()(const int line, const int column) const;
};

#endif
