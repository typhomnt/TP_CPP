#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector v1(3,5.);
	Dvector v2(3,4.);
	assert(v1 != v2);
	cout << "SECOND TEST DE L'INEGALITE (VALEUR DIFFERENTE) : OK" << endl;	
}
