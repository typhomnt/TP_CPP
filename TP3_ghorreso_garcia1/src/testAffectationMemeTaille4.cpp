#include "Darray.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Darray c(150);
	Darray d(200);
	c.fillRandomly();
	d.fillRandomly();
	Darray a(c.view(true, 0, 100));
	Darray b(d.view(true, 0, 100));
	a = b;
	for (int i = 0; i < a.size(); i++) {
		assert(a(i) == b(i));
	}
	assert(a.isOwner() == true);
	cout << "TEST DE L'AFFECTATION D'UN DARRAY DE MEME TAILLE (CAS 4) : OK" << endl;
}
