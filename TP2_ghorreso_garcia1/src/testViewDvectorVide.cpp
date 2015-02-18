#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector v;
	try {
		v.view(true, 0, 1);
	} catch (std::exception const& e) {
		cout << "TEST DE VIEW APPLIQUE A UN DVECTOR VIDE : OK" << endl;
	}
}
