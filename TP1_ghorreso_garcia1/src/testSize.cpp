#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

void testSize() {
	Dvector v(3, 6.8);
	assert(v.size() == 3);
	cout << "TEST DU SIZE : OK" << endl;
}

int main(){
	testSize();
}
