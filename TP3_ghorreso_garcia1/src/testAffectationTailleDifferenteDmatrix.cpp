#include "Dmatrix.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dmatrix a(40, 60);
	Dmatrix b(50, 50);
	b.fillRandomly();
	a = b;
	assert(a.lines() == b.lines());
	assert(a.columns() == b.columns());
	for (int i = 0; i < a.lines(); i++) {
		for (int j = 0; j < a.columns(); j++) {
			assert(a(i,j) == b(i,j));
		}
	}
	assert(a.isOwner() == true);
	cout << "TEST DE L'AFFECTATION D'UN DMATRIX DE TAILLE DIFFERENTE : OK" << endl;
}