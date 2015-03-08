#include "Dvector.h"
#include "Darray.h"
#include <fstream>
#include <cassert>
#include <stdexcept>

Dvector::Dvector(): Darray() {};

Dvector::Dvector(const int dim, const double val): Darray(dim,val) {};

Dvector::Dvector(const Dvector& d): Darray(d) {};

Dvector::Dvector(const std::string file): Darray(file) {};

Dvector::~Dvector() {};

Dvector Dvector::view(bool copy, const int start, const int count) const{
	if(this->sizeD == 0)
		throw std::logic_error("The Darray must have a positive size");
	if(count == 0)
		throw std::out_of_range("count must be positive");
	if(start < 0 || start + count > this->sizeD - 1)
		throw std::out_of_range("start or (start + count) out of range");
	if(copy == true){
		Dvector res1(count);
		for(int i = 0 ; i < count ; i++)
			res1.data[i] = this->data[i + start];
		res1.isProp = true;
		return res1;
	}
	else {
		// Res.data pointe vers l'élément d'indice start de this->data
		Dvector res2(count);
		res2.data = this->data + start*sizeof(double)/8;
		res2.isProp = false;
		return res2;
	}
}

double operator*(const Dvector& d1, const Dvector& d2) {
	if (d1.size() != d2.size())
		throw std::invalid_argument("Different sizes in scalar product");
	if (d1.size() == 0)
		throw std::invalid_argument("Null Dvector in scalar product");
	double res = 0;
	for (int i = 0; i < d1.size(); i++) {
		res += d1(i)*d2(i);
	}
	return res;
}
