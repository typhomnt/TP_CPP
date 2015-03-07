#include "Dvector.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cassert>
#include <sstream>
using namespace std;

int main() {
	Dvector d1(5, 3.2);
	Dvector d2(4, 5.4);
	try {
		d1*d2;
	} catch (const invalid_argument& e) {
		cout << "TEST DE L'ERREUR DANS LE PRODUIT SCALAIRE (TAILLE DIFFERENTE) : OK" << endl;
	};
}
