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
	Dvector v2;
	v2 = v1.view(false, 25, 50);
	for (int i = 0; i < v2.size(); i++) {
		assert(v2(i) == v1(i+25));
	}
	assert(v2.isOwner() == false);
	cout << "TEST DE VIEW AVEC COPY=FALSE : OK" << endl;
}
