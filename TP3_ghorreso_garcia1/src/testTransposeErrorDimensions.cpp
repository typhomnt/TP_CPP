#include "Dmatrix.h"
#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	Dmatrix a(5, 4);
	try {
		a.transpose();
	} catch (invalid_argument const& e) {
		cout << "TEST DE LA TRANSPOSITION D'UNE MATRICE NON CARREE: OK" << endl;
	}
}
