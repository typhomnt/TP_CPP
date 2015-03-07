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
	Dmatrix copie(a);
	a *= b;
	double somme;
	for (int i = 0; i < a.lines(); i++) {
		for (int j = 0; j < a.columns(); j++) {
			somme = 0.0;
			for (int k = 0; k < copie.columns(); k++) {
				somme += copie(i,k)*b(k,j);
			}
			assert(a(i,j) == somme);
		}
	}
	cout << "TEST DE LA MUTLIPLICATION INTERNE DE DMATRIX : OK" << endl;
}
