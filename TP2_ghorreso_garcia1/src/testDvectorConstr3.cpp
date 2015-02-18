#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector v(5, 6.4);
	Dvector copie(v);
	stringstream str_v, str_copie;
	v.display(str_v);
	copie.display(str_copie);
	assert(str_v.str() == str_copie.str());
	assert(copie.isOwner() == v.isOwner());
	cout << "TEST DU CONTRUCTEUR PAR COPIE : OK" << endl;
}
