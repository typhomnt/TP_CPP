#include "Darray.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Darray a(100);
	Darray c(150);
	c.fillRandomly();
	Darray b(c.view(true, 0, 50));
	a = b;
	for (int i = 0; i < a.size(); i++) {
		assert(a(i) == b(i));
	}
	assert(a.isOwner() == true);
	cout << "TEST DE L'AFFECTATION D'UN DARRAY DE TAILLE DIFFERENTE (CAS 2) : OK" << endl;
}
