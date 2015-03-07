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
	Darray v1Initial(v1);
	v1 += v2;
	for (int i = 0; i < v1.size(); i++) {
		assert(v1(i) == (v1Initial(i) + v2(i)));
	}
	cout << "TEST DE L'ADDITION AVEC UN DARRAY : OK" << endl;
}
