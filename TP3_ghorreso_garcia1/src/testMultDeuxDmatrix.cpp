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
	Dmatrix b(4, 6, 4.3);
	Dmatrix c(5,6);
	c = a*b;
	double somme;
	for (int i = 0; i < c.lines(); i++) {
		for (int j = 0; j < c.columns(); j++) {
			somme = 0.0;
			for (int k = 0; k < a.columns(); k++) {
				somme += a(i,k)*b(k,j);
			}
			assert(c(i,j) == somme);
		}
	}
	cout << "TEST DE DMATRIX MULT DMATRIX : OK" << endl;
}
