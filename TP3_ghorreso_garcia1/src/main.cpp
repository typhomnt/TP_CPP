#include "Darray.h"
#include "Dvector.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <sstream>
using namespace std;

int main() {
	Dvector d1(4,5.5);
	Dvector d2(4,4.4);
	d1 += d2;
	d1.display(cout);
	cout << d1*d2 << endl;
}
