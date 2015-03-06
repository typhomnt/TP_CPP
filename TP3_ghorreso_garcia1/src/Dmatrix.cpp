#include "Dmatrix.h"
#include <fstream>
#include <cassert>
#include <stdexcept>

Dmatrix::Dmatrix(): Darray() {
	this->m = 0;
	this->n = 0;
}

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
}

Dmatrix::Dmatrix(const Dmatrix& mat): Darray(mat) {
	this->m = mat.m;
	this->n = mat.n;
}

Dmatrix::~Dmatrix() {};

double Dmatrix::lines() const {
	return this->m;
}

double Dmatrix::columns() const {
	return this->n;
}

double& Dmatrix::operator()(const int line, const int column) const {
	if(line > m - 1 || line < 0)
		throw std::out_of_range("line argument out of range");
	if(column > n - 1 || column < 0)
		throw std::out_of_range("column argument out of range");
	return this->data[column + line*n];
}

Dmatrix& Dmatrix::operator=(const Dmatrix& mat) {
	Darray::operator=((Darray&) mat);
	this->m = mat.m;
	this->n = mat.n;
	return *this;
}

Dmatrix& Dmatrix::operator*=(const Dmatrix& mat) {
	if (mat.sizeD == 0)
		throw std::invalid_argument("null argument in multiplication");
	if (this->n != mat.m)
		throw std::invalid_argument("incorrect dimensions in multiplication");
	Dmatrix copie(*this);
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++) {
			this->data[j+i*n] = 0;
			for (int k = 0; k < this->n; k++) {
				this->data[j+i*n] += copie(i,k) * mat(k,j);
			}
		}
	}
	return *this;
}

Dmatrix& Dmatrix::transpose() {
	if (this->m != this->n)
		throw std::invalid_argument("the object must be a square matrix");
	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < this->m; j++) {
			this->data[j+i*n] = this->data[i+j*n];
		}
	}
	return *this;
}

Dmatrix operator*(const Dmatrix& mat1, const Dmatrix& mat2) {
	Dmatrix res(mat1);
	res *= mat1;
	return res;
}

Dvector operator*(const Dmatrix& mat, const Dvector& d) {
	if (mat.size() == 0 || d.size() == 0)
		throw std::invalid_argument("null argument in multiplication");
	if (mat.columns() != d.size())
		throw std::invalid_argument("incorrect dimensions in multiplication");
	Dvector res(d.size());
	for (int i = 0; i < res.size(); i++) {
		for (int k = 0; k < mat.columns(); k++) {
			res(i) = mat(i,k)*d(k);
		}
	}
	return res;
}
