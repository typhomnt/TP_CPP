#include "Darray.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Darray v(5, 5.8);
	try {
		v.view(true, -2, 3);
	} catch (std::exception const& e) {
		cout << "TEST DE VIEW AVEC START < 0 : OK" << endl;
	}
}
