#include "Darray.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Darray v1(100);
	v1.fillRandomly();
	Darray v(3);
	v = -v1;
	for (int i = 0; i < v.size(); i++) {
		assert(v(i) == -v1(i));
	}
	cout << "TEST DE L'OPPOSE D'UN DARRAY : OK" << endl;
}
