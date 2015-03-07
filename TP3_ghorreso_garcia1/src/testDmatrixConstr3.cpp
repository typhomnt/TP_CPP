#include "Dmatrix.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dmatrix v(5, 4, 6.4);
	Dmatrix copie(v);
	stringstream str_v, str_copie;
	v.display(str_v);
	copie.display(str_copie);
	assert(str_v.str() == str_copie.str());
	assert(copie.isOwner() == v.isOwner());
	cout << "TEST DU CONTRUCTEUR PAR COPIE DE DMATRIX : OK" << endl;
}
