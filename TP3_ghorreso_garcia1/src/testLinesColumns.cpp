#include "Dmatrix.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dmatrix v(5, 4);
	assert(v.lines() == 5);
	assert(v.columns() == 4);
	cout << "TEST DE LINES ET COLUMNS : OK" << endl;
}
