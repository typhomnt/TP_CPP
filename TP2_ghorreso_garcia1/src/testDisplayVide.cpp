#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector v;
	stringstream str;
	v.display(str);
	assert(str.str() == "");
	cout << "TEST DU DISPLAY D'UN DVECTOR VIDE: OK" << endl;
}