#include "Darray.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Darray v1(5,4.6);
	Darray v2(5);
	v2 = v1 / 2.3;
	for (int i = 0; i < v2.size(); i++)
		assert(v2(i) == v1(i) / 2.3);
	cout << "TEST DE DARRAY DIVISE DOUBLE : OK" << endl;
}