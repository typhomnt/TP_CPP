#ifndef DARRAYH
#define DARRAYH
#include <iostream>
#include <istream>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @file Darray.h
 *
 * Classe representant les tableaux
 */

class Darray {
	protected:
		int sizeD;
		double *data;
		bool isProp;

	public:
		Darray();
		Darray(const int dim, const double val=0.0);
		Darray(const Darray& d);
		Darray(const std::string file);
		~Darray();

		int size() const;
		const double* getData() const;
		bool isOwner() const;

		void display(std::ostream& str) const;
		void fillRandomly();

		double& operator()(const int i) const;
		Darray view(bool copy, const int start, const int count) const;

		Darray& operator=(const Darray& d);

		Darray& operator+=(const double r);
		Darray& operator-=(const double r);
		Darray& operator*=(const double r);
		Darray& operator/=(const double r);

		Darray& operator+=(const Darray& d);
		Darray& operator-=(const Darray& d);

		bool operator==(const Darray& d) const;
		bool operator!=(const Darray& d) const;
};

Darray operator+(const Darray& d, const double r);
Darray operator-(const Darray& d, const double r);
Darray operator*(const Darray& d, const double r);
Darray operator/(const Darray& d, const double r);

Darray operator+(const double r, const Darray& d);
Darray operator*(const double r, const Darray& d);

Darray operator+(const Darray& d1, const Darray& d2);
Darray operator-(const Darray& d1, const Darray& d2);

Darray operator-(const Darray& d);
#endif
