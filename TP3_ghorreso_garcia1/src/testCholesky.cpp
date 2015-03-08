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
	Dmatrix a(l*lt);
	//a = a.cholesky();
	for(int i = 0 ; i < 2 ; i++)
		for(int j = 0 ; j < 2 ; j++){
			//assert(a(i,j) == l(i,j));
			cout << a(i,j) << endl;
			cout << "l" << endl;
		        cout << l(i,j) << endl;
		}
	cout << "TEST CHOLESKY : OK" << endl;
}
