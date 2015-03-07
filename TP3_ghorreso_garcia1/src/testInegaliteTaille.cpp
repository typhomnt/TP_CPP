#include "Darray.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Darray v1(3,5.);
	Darray v2(4,5.);
	assert(v1 != v2);
	cout << "TEST DE L'INEGALITE (TAILLE DIFFERENTE) : OK" << endl;	
}
