#include "Dmatrix.h"
#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	Dmatrix a(2,2,2);
	a(0,1) = 0;
	try{
		Dmatrix T = a.cholesky();
	}catch (std::exception const& e) {
		cout << "TEST DE CHOLESKY AVEC UNE MATRICE NON SYMETRIQUE : OK" << endl;
	}
  
}
