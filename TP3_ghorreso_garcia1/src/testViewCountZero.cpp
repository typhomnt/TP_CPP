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
		v.view(true, 2, 0);
	} catch (std::exception const& e) {
		cout << "TEST DE VIEW AVEC COUNT=0 : OK" << endl;
	}
}
