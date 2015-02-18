#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector v(5, 5.8);
	try {
		v.view(true, 2, 3);
	} catch (std::exception const& e) {
		cout << "TEST DE VIEW AVEC START + COUNT > SIZE-1 : OK" << endl;
	}
}
