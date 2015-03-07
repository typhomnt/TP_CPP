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
