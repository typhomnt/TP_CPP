#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector vRef(5,5.5);
	Dvector v(3);
	string file("testFluxEntrant.txt");
	fstream testFile(file.c_str());
	// On remplit le fichier avec vRef
	vRef.display(testFile);
	// On revient au début du fichier
	testFile.clear();
	testFile.seekg(0,testFile.beg);
	// On lit le fichier dans v
	testFile >> v;
	for (int i = 0; i < v.size(); i++) {
		assert(v(i) == vRef(i));
	}
	cout << "TEST DU FLUX ENTRANT : OK" << endl;
}
