#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector v(3,6.5);
	for (int i = 0; i < v.size(); i++) {
		assert(v.getData()[i] == 6.5);
	}
	cout << "TEST DE GETDATA : OK" << endl;
}