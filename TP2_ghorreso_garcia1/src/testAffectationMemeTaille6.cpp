#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector a;
	Dvector c(150);
	c.fillRandomly();
	Dvector b(c.view(true, 0, 100));
	a = b;
	for (int i = 0; i < a.size(); i++) {
		assert(a(i) == b(i));
	}
	assert(a.isOwner() == true);
	cout << "TEST DE L'AFFECTATION D'UN DVECTOR DE MEME TAILLE (CAS 6) : OK" << endl;	
}
