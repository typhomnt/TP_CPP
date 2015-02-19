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
	Dvector v1Initial(v1);
	v1 -= v2;
	for (int i = 0; i < v1.size(); i++) {
		assert(v1(i) == (v1Initial(i) - v2(i)));
	}
	cout << "TEST DE LA SOUSTRACTION AVEC UN DVECTOR : OK" << endl;
}
