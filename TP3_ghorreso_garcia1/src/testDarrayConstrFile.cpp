#include "Darray.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Darray ref(100,0.2);
	ref.fillRandomly();
	string file("testDarrayConstrFile.txt");
	ofstream testFile(file.c_str());
	ref.display(testFile);
	Darray vt("testDarrayConstrFile.txt");
	stringstream str_ref, str_vt;
	ref.display(str_ref);
	vt.display(str_vt);
	assert(str_ref.str() == str_vt.str());
	assert(vt.isOwner() == true);
	cout << "TEST DU CONSTRUCTEUR AVEC FICHIER DE DARRAY: OK" << endl;
}
