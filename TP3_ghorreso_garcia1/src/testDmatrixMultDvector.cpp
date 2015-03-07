#include "Dmatrix.h"
#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	Dmatrix a(5, 4, 6.5);
	Dvector x(4, 4.3);
	Dvector y(5);
	y = a*x;
	double somme;
	for (int i = 0; i < y.size(); i++) {
		somme = 0.0;
		for (int k = 0; k < x.size(); k++) {
			somme += a(i,k)*x(k);
		}
		assert(y(i) == somme);
	}
	cout << "TEST DE DMATRIX MULT DVECTOR : OK" << endl;
}
