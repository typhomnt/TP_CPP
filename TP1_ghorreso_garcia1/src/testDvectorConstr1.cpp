#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

void testDvectorConstr1() {
	Dvector v;
	assert(v.size() == 1);
	assert(v.getVect()[0] == 0);
	cout << "TEST DU CONSTRUCTEUR PAR DEFAUT : OK" << endl;
}

int main(){
	testDvectorConstr1();
}
