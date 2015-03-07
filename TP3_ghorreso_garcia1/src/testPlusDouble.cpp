#include "Darray.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Darray v(5,3.5);
	v += 2.3;
	for (int i = 0; i < v.size(); i++) {
		assert(v(i) == 5.8);
	}
	cout << "TEST DE L'ADDITION AVEC UN DOUBLE : OK" << endl;	
}
