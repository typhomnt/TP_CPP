#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector a;
	Dvector b(100);
	a = b;
	for (int i = 0; i < a.size(); i++) {
		assert(a.getData()[i] == b.getData()[i]);
	}
	assert(a.isOwner() == true);
	cout << "TEST DE L'AFFECTATION D'UN DVECTOR DE MEME TAILLE (CAS 5) : OK" << endl;
}
