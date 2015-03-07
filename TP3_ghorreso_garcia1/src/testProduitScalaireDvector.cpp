#include "Dvector.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cassert>
#include <sstream>
using namespace std;

int main() {
	Dvector d1(5, 4.6);
	Dvector d2(5, 3.5);
	double res = d1*d2;
	double somme = 0;
	for (int i = 0; i < d1.size(); i++) {
		somme += d1(i)*d2(i);
	}
	assert(res == somme);
	cout << "TEST DU PRODUIT SCALAIRE DE DVECTOR : OK " << endl;
}
