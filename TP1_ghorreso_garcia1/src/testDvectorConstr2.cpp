#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

void testDvectorConstr2() {
	Dvector v(2, 3.5);
	assert(v.size() == 2);
	stringstream str;
	v.display(str);
	assert(str.str() == "3.5\n3.5\n");
	cout << "TEST DU CONTRUCTEUR AVEC INITIALISATION: OK" << endl;
}

int main(){
	testDvectorConstr2();
}

