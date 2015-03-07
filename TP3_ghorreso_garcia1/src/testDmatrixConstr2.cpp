#include "Dmatrix.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dmatrix v(2, 3, 3.5);
	assert(v.size() == 6);
	assert(v.lines() == 2);
	assert(v.columns() == 3);
	stringstream str;
	v.display(str);
	assert(str.str() == "3.5\n3.5\n3.5\n3.5\n3.5\n3.5\n");
	assert(v.isOwner() == true);
	cout << "TEST DU CONTRUCTEUR AVEC INITIALISATION DE DMATRIX : OK" << endl;
}
