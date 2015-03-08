#include "Dmatrix.h"
#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	Dmatrix mat(10,10);
	mat.fillRandomly();
	Dvector d = mat.line(true,1);
	for(int i = 0 ; i < mat.columns() ; i++){
		assert(d(i) == mat(1,i));
	}
	cout << "TEST LINE : OK" << endl;	
}
