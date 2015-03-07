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
	Dmatrix a(5, 4, 6.5);
	Dmatrix b(7, 8, 7.4);
	try {
		a *= b;
	} catch (invalid_argument const& e) {
		cout << "TEST DE LA MUTLIPLICATION INTERNE AVEC DIMENSIONS INCOMPATIBLES : OK" << endl;
	}
}
