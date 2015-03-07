#include "Darray.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Darray v(5,3.5);
	v *= 2.0;
	for (int i = 0; i < v.size(); i++) {
		assert(v(i) == 7.0);
	}
	cout << "TEST DE LA MULTIPLICATION AVEC UN DOUBLE : OK" << endl;	
}
