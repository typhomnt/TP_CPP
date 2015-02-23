#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

void testFillRandomly(){
	cout << "ALEATOIRE" << std::endl;
	Dvector v(5);
	v.fillRandomly();
	Dvector v2(5);
	cout << "v1 = " << std::endl;
	v.display(cout);
	v2.fillRandomly();
	cout << "v2 = " << std::endl;
	v2.display(cout); 
}

int main(){
	testFillRandomly();
}
