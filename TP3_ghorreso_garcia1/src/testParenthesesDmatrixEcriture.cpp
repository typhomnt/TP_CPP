#include "Dmatrix.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dmatrix v(5, 4, 3.5);
	for (int i = 0; i < v.lines(); i++) {
		for (int j = 0; j < v.columns(); j++) {
			v(i,j) = i*j;
		}
	}
	for (int i = 0; i < v.lines(); i++) {
		for (int j = 0; j < v.columns(); j++) {
			assert(v(i,j) == i*j);
		}
	}
	cout << "TEST DES PARENTHESES DE DMATRIX (ECRITURE) : OK" << endl;
}
