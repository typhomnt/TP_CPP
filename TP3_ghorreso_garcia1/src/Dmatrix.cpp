#include "Dmatrix.h"
#include "Dvector.h"
#include <fstream>
#include <cassert>
#include <stdexcept>
#include <cmath>

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

Dvector Dmatrix::line(const bool copy, const int pos) const{
	if(pos > m - 1 || pos < 0)
		throw std::out_of_range("pos argument out of range");
	Dvector d(this->size());
	for(int i = 0 ; i < this->size() ; i++)
		d(i) = (this->getData())[i];
	return d.view(copy, n*pos, n - 1 +n*pos);
}

Dvector Dmatrix::column(const int pos) const{
	if(pos > n - 1 || pos < 0)
		throw std::out_of_range("pos argument out of range");
	Dvector d(m);
	for(int i = 0 ; i < m ; i++){
		d(i) = (*this)(i,pos);
	}
	return d;
}

Dmatrix Dmatrix::cholesky(){
	if(m != n)
		throw std::invalid_argument("The matrix should be a square one");
	Dmatrix L(m,m);
	double sum_square;
	double sum_prod;
	for(int i = 0 ; i < m ; i++){
		sum_square = 0;
		for(int s = 0 ; s < i ; s++)
			sum_square += pow(L(i,s),2);
		L(i,i) = sqrt((*this)(i,i) - sum_square);
		for(int j = i + 1 ; j < m ; j++){
			sum_prod = 0;
			for(int s = 0 ; s < i ; s++)
				sum_prod += L(j,s)*L(i,s);
			L(j,i) = ((*this)(j,i) - sum_prod)/L(i,i);
			
		}
	}
	return L;
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
	// On supprime le tableau de *this car il peut changer de taille
	delete [] this->data;
	this->n = mat.n;
	this->data = new double[this->m*this->n];
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < mat.n; j++) {
			this->data[j+i*(this->n)] = 0;
			for (int k = 0; k < mat.m; k++) {
				this->data[j+i*n] += copie(i,k) * mat(k,j);
			}
		}
	}
	return *this;
}

Dmatrix& Dmatrix::transpose() {
	if (this->m != this->n)
		throw std::invalid_argument("the object must be a square matrix");
	Dmatrix copie(*this);
	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < this->m; j++) {
			this->data[i+j*n] = copie.data[j+i*(copie.n)];
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
			res(i) += mat(i,k)*d(k);
		}
	}
	return res;
}
