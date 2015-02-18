#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector c(150);
	Dvector d(200);
	c.fillRandomly();
	d.fillRandomly();
	Dvector a(c.view(true, 0, 100));
	Dvector b(d.view(true, 0, 100));
	a = b;
	for (int i = 0; i < a.size(); i++) {
		assert(a.getData()[i] == b.getData()[i]);
	}
	assert(a.isOwner() == false);
	cout << "TEST DE L'AFFECTATION D'UN DVECTOR DE MEME TAILLE (CAS 4) : OK" << endl;
}
