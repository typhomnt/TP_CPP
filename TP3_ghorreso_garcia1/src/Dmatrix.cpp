#include "Dmatrix.h"
#include <fstream>
#include <cassert>
#include <stdexcept>

Dmatrix::Dmatrix(): Darray() {
	this->m = 0;
	this->n = 0;
};

Dmatrix::Dmatrix(const int nbLignes, const int nbColonnes, const double val) {
	std::cout << "appel au constructeur avec dimension et "
		"valeur initiale" << std::endl;
	this->sizeD = nbLignes * nbColonnes;
	this->data = new double[nbLignes*nbColonnes];
	this->isProp = true;
	this->m = nbLignes;
	this->n = nbColonnes;

	for (int i = 0; i < this->sizeD; i++) {
		this->data[i] = val;
	};
};

Dmatrix::Dmatrix(const Dmatrix& mat): Darray(mat) {
	this->m = mat.m;
	this->n = mat.n;
};

Dmatrix::~Dmatrix() {};


