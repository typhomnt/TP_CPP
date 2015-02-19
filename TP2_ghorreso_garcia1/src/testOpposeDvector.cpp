#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector v1(100);
	v1.fillRandomly();
	Dvector v(3);
	v = -v1;
	for (int i = 0; i < v.size(); i++) {
		assert(v(i) == -v1(i));
	}
	cout << "TEST DE L'OPPOSE D'UN DVECTOR : OK" << endl;	
}
