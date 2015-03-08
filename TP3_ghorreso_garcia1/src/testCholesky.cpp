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
	Dmatrix a(2,2);
	a(0,0)=4;
	a(0,1)=4;
	a(1,0)=4;
	a(1,1)=8;
	a = a.cholesky();
	for(int i = 0 ; i < 2 ; i++)
		for(int j = 0 ; j < 2 ; j++){
			assert(a(i,j) == l(i,j));
			/*cout << a(i,j) << endl;
			cout << "l" << endl;
		        cout << l(i,j) << endl;*/
		}
	cout << "TEST CHOLESKY : OK" << endl;
}
