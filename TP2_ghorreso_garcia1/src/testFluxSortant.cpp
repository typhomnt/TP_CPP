#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector v(3,5.4);
	stringstream out;
	out << v;
	assert(out.str() == "5.4\n5.4\n5.4\n");
	cout << "TEST DU FLUX SORTANT : OK" << endl;
}
