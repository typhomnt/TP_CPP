#include "Dmatrix.h"
#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	Dmatrix l(2,2,2);
	l(0,1) = 0;
	Dmatrix lt(l);
	lt.transpose();
	Dmatrix a = l*lt;
	Dmatrix T = a.cholesky();
	for(int i = 0 ; i < 2 ; i++)
		for(int j = 0 ; j < 2 ; j++){
			assert(T(i,j) == l(i,j));
		}
	cout << "TEST CHOLESKY : OK" << endl;
}
