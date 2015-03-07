#include "Darray.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Darray v(2, 3.5);
	assert(v.size() == 2);
	stringstream str;
	v.display(str);
	assert(str.str() == "3.5\n3.5\n");
	assert(v.isOwner() == true);
	cout << "TEST DU CONTRUCTEUR AVEC INITIALISATION DE DARRAY : OK" << endl;
}
