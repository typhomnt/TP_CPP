#include "Darray.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Darray c(150);
	c.fillRandomly();
	Darray a(c.view(false, 20, 100));
	Darray b(50, 2.);
	try {
		a = b;
	} catch (std::exception const& e) {
		cout << "TEST DE L'AFFECTATION D'UN DARRAY DE TAILLE DIFFERENTE (CAS 3) : OK" << endl;
	}
}
