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
	Dmatrix a(5,4,3.2);
	Dvector x;
	Dvector y(5);
	try {
		y = a*x;
	} catch (invalid_argument const& e) {
		cout << "TEST DE DMATRIX MULT DVECTOR=NULL : OK" << endl;
	}
}
