#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector v(3);
	assert(v.isOwner() == true);
	cout << "TEST DE ISOWNER : OK" << endl;
}