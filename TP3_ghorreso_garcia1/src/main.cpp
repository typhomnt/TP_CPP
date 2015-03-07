#include "Darray.h"
#include "Dvector.h"
#include "Dmatrix.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cassert>
#include <sstream>
using namespace std;

void testProduitScalaire() {
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

void testProduitScalaireErrorSize() {
	Dvector d1(5, 3.2);
	Dvector d2(4, 5.4);
	try {
		d1*d2;
	} catch (const invalid_argument& e) {
		cout << "TEST DE L'ERREUR DANS LE PRODUIT SCALAIRE (TAILLE DIFFERENTE) : OK" << endl;
	};
}

void testProduitScalaireNullArgument() {
	Dvector d1;
	Dvector d2(4, 5.4);
	try {
		d1*d2;
	} catch (const invalid_argument& e) {
		cout << "TEST DE L'ERREUR DANS LE PRODUIT SCALAIRE (ARGUMENT NULL) : OK" << endl;
	};
}

/*void testTranspose() {
	Dmatrix mat(3,3, 5.5);
	for (int i = 0)
}*/
int main() {
	testProduitScalaire();
	testProduitScalaireErrorSize();
	testProduitScalaireNullArgument();
}
