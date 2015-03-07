#ifndef DMATRIXH
#define DMATRIXH
#include "Darray.h"
#include "Dvector.h"

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

		double lines() const;
		double columns() const;

		double& operator()(const int line, const int column) const;
		
		Dvector line(const bool copy, const int pos) const;
		
		Dvector column(const int pos) const;
		
		Dmatrix cholesky();

		Dmatrix& operator=(const Dmatrix& mat);

		Dmatrix& operator*=(const Dmatrix& mat);

		Dmatrix& transpose();

};

Dmatrix operator*(const Dmatrix& mat1, const Dmatrix& mat2);

Dvector operator*(const Dmatrix& mat, const Dvector& d);

#endif
