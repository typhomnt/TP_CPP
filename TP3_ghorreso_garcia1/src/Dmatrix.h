#ifndef DMATRIXH
#define DMATRIXH
#include "Darray.h"
#include "Dvector.h"

/**
 * @file Dmatrix.h
 *
 * Classe representant les matrices de reels.
 */
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
		 * @param mat : matrice qui va etre copie
		 */
		Dmatrix(const Dmatrix& mat);
		/**
		 * Destructeur
		 */
		~Dmatrix();

		/**
		 * Accesseur au champ m (nombre de lignes) de Dmatrix
		 * @return champ m de l'objet
		 */
		double lines() const;
		/**
		 * Accesseur au champ n (nombre de colonnes) de Dmatrix
		 * @return champ n de l'objet
		 */
		double columns() const;

		/**
		 * Permet d'acceder a l'element en line-ieme ligne et
		 * en column-ième colonne de la matrice .
		 * @param line : numero de la ligne
		 * @param column : numero de la colonne
		 * @return M(line,column)
		 */
		double& operator()(const int line, const int column) const;
		
		/**
		 * Copie la pos-ieme ligne et la renvoie sous la forme d'une
		 * Dvector grace a la methode view de Dvector.
		 * @param copy : si copy==true, alors la methode recopie une par une les
	     * valeurs de la matrice; si copy==false, alors la methode fait coincider
	     * l'adresse du data de l'objet resultant et l'adresse de la pos-ieme
	     * ligne de l'objet courant
	     * @param pos : numero de la ligne qui doit etre copie
	     * @return pos-ieme ligne
		 */
		Dvector line(const bool copy, const int pos) const;
		
		/**
		 * Copie la pos-ieme colonne, en recopiant une par une les valeurs de
		 * la matrice, et la renvoie sous la forme d'une Dvector.
		 * @param pos : numero de la ligne qui doit etre copie
		 * @return pos-ieme colonne
		 */
		Dvector column(const int pos) const;
		
		/**
		 * Effectue la factorisation de Cholesky pour les matrices symetriques
		 * definies positives.
		 * @return matrice triangulaire inferieure L telle que A = L*L' ou L'
		 * est la transposee de L et A est la matrice sur laquelle on applique
		 * Cholesky
		 */
		Dmatrix cholesky();

		/**
		 * Operateur permettant d'affecter les attributs de l'objet donné en
		 * parametre a l'objet courant. La modification de l'attribut isProp
		 * est la même que pour les Darray.
		 * @param mat : reference vers la matrice
		 * @return reference vers l'objet avec les nouveaux attributs
		 */
		Dmatrix& operator=(const Dmatrix& mat);

		/**
		 * Operateur realisant le produit de l'objet courant par une matrice
		 * non nulle. On doit avoir this->n = mat.m.
		 * @param mat : reference vers la matrice
		 * @return reference vers la nouvelle matrice
		 */
		Dmatrix& operator*=(const Dmatrix& mat);

		/**
		 * Calcule la transposee d'une matrice. Cette methode est chainable,
		 * c'est-a-dire qu'on peut faire a.transpose().transpose() par
		 * exemple. La matrice doit etre carree.
		 * @return reference vers la nouvellle matrice
		 */
		Dmatrix& transpose();

};

/**
 * Operateur permettant le produit de deux matrices. Les deux matrices doivent
 * etre non nulles et mat1.n = mat2.m.
 * @param mat1 : reference vers la premiere matrice
 * @param mat2 : reference vers la seconde matrice
 * @return la matrice resultante
 */
Dmatrix operator*(const Dmatrix& mat1, const Dmatrix& mat2);

/**
 * Operateur permettant le produit d'un Dmatrix par un Dvector.
 * Les deux elements doivent etre non nuls et mat.n = d.sizeD.
 * @param mat : reference vers la matrice
 * @param d : reference vers le vecteur
 * @return la matrice resultante
 */
Dvector operator*(const Dmatrix& mat, const Dvector& d);

#endif
