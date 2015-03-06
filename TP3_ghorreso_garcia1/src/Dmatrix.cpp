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

double& Dmatrix::operator()(const int line, const int column) const {
	if(line > m - 1 || line < 0)
		throw std::out_of_range("line argument out of range");
	if(column > n - 1 || column < 0)
		throw std::out_of_range("column argument out of range");
	return this->data[column + line*n];
}


