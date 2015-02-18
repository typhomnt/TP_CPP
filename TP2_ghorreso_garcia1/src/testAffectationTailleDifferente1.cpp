#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	cout << "cas 1" << endl;
	Dvector a(100);
	cout << "a.isProp = " << a.isOwner() << endl;
	Dvector b(50);
	b.fillRandomly();
	a = b;
	for (int i = 0; i < a.size(); i++) {
		assert(a.getData()[i] == b.getData()[i]);
	}
	assert(a.isOwner() == true);
	cout << "b.isProp = " << b.isOwner() << endl;
	cout << "TEST DE L'AFFECTATION D'UN DVECTOR DE TAILLE DIFFERENTE (CAS 1) : OK" << endl;
}
