#include "Darray.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Darray v;
	try {
		v.view(true, 0, 1);
	} catch (std::exception const& e) {
		cout << "TEST DE VIEW APPLIQUE A UN DARRAY VIDE : OK" << endl;
	}
}
