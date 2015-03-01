#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector v(5,3.5);
	for (int i = 0; i < v.size(); i++) {
		v(i) = i;
	}
	for (int i = 0; i < v.size(); i++) {
		assert(v(i) == i);
	}
	cout << "TEST DES PARENTHESES (ECRITURE) : OK" << endl;
}