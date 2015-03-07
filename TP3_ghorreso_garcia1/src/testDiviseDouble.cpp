#include "Darray.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Darray v(5,3.5);
	v /= 7.0;
	for (int i = 0; i < v.size(); i++) {
		assert(v(i) == 0.5);
	}
	cout << "TEST DE LA DIVISION AVEC UN DOUBLE : OK" << endl;	
}
