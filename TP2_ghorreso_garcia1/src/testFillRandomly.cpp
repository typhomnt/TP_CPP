#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

void testFillRandomly(){
	Dvector v(1000);
	v.fillRandomly();
	for(int i = 0; i < v.size(); i++) {
		assert(v(i) >= 0);
		assert(v(i) <= 1);
	}
	cout << "TEST DE FILLRANDOMLY : OK" << endl;
}

int main(){
	testFillRandomly();
}
