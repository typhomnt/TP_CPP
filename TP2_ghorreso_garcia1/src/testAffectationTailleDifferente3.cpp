#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector c(150);
	c.fillRandomly();
	Dvector a(c.view(true, 20, 100));
	Dvector b(50, 2.);
	try {
		a = b;
	} catch (std::exception const& e) {
		cout << "TEST DE L'AFFECTATION D'UN DVECTOR DE TAILLE DIFFERENTE (CAS 3) : OK" << endl;
	}
}
