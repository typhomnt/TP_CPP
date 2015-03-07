#include "Darray.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Darray v1(100);
	Darray v2(100);
	v1.fillRandomly();
	v2.fillRandomly();
	Darray v(3);
	v = v1 - v2;
	for (int i = 0; i < v.size(); i++) {
		assert(v(i) == (v1(i) - v2(i)));
	}
	cout << "TEST DE LA SOUSTRACTION DE DEUX DARRAY : OK" << endl;
}
