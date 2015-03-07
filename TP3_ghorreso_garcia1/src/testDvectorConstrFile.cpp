#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	Dvector ref(100,0.2);
	ref.fillRandomly();
	string file("testDvectorConstrFile.txt");
	ofstream testFile(file.c_str());
	ref.display(testFile);
	Dvector vt("testDvectorConstrFile.txt");
	stringstream str_ref, str_vt;
	ref.display(str_ref);
	vt.display(str_vt);
	assert(str_ref.str() == str_vt.str());
	assert(vt.isOwner() == true);
	cout << "TEST DU CONSTRUCTEUR AVEC FICHIER DE DVECTOR: OK" << endl;
}
