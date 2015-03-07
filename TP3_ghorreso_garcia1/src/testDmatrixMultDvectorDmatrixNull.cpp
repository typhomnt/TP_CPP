#include "Dmatrix.h"
#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <sstream>
using namespace std;

int main() {
	Dmatrix a;
	Dvector x(4, 4.3);
	Dvector y(4);
	try {
		y = a*x;
	} catch (invalid_argument const& e) {
		cout << "TEST DE DMATRIX=NULL MULT DVECTOR : OK" << endl;
	}
}
