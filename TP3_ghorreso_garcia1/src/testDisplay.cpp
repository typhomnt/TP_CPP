#include "Darray.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

void testDisplay(){
	Darray v(3, 6.8);
	stringstream str;
	v.display(str);
	assert(str.str() == "6.8\n6.8\n6.8\n");
	cout << "TEST DU DISPLAY : OK" << endl;
}

int main(){
	testDisplay();
}
