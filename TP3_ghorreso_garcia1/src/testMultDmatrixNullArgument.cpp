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
	Dmatrix b;
	try {
		a *= b;
	} catch (invalid_argument const& e) {
		cout << "TEST DE LA MUTLIPLICATION INTERNE PAR DMATRIX=NULL : OK" << endl;
	}
}
