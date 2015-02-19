#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector v1(100);
	Dvector v2(100);
	v1.fillRandomly();
	v2.fillRandomly();
	Dvector v(3);
	v = v1 - v2;
	for (int i = 0; i < v.size(); i++) {
		assert(v(i) == (v1(i) - v2(i)));
	}
	cout << "TEST DE LA SOUSTRACTION DE DEUX DVECTOR : OK" << endl;
}
