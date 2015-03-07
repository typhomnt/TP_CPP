#include "Dmatrix.h"
#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	Dmatrix a(5, 5);
	for (int i = 0; i < a.lines(); i++) {
		for (int j = 0; j < a.columns(); j++) {
			a(i,j) = i-j;
		}
	}
	Dmatrix copie(a);
	a.transpose();
	for (int i = 0; i < a.lines(); i++) {
		for (int j = 0; j < a.columns(); j++) {
			assert(a(i,j) == copie(j,i));
		}
	}
	cout << "TEST DE LA TRANSPOSITION : OK" << endl;
}
