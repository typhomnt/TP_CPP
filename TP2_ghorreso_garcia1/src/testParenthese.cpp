#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

void testParenthese(){
	Dvector v(5,3.5);
	for (int i = 0; i < v.size(); i++) {
		assert(v(i) == 3.5);
	}
	cout << "TEST DES PARENTHESES : OK" << endl;
}

void testPlusDouble(){
	Dvector v(5,3.5);
	v += 2.3;
	for (int i = 0; i < v.size(); i++) {
		assert(v.getData()[i] == 5.8);
	}
	cout << "TEST DE L'ADDITION AVEC UN DOUBLE : OK" << endl;
}

void testMoinsDouble(){
	Dvector v(5,3.5);
	v -= 5.0;
	for (int i = 0; i < v.size(); i++) {
		assert(v.getData()[i] == -1.5);
	}
	cout << "TEST DE LA SOUSTRACTION AVEC UN DOUBLE : OK" << endl;
}

void testMultDouble(){
	Dvector v(5,3.5);
	v *= 2.0;
	for (int i = 0; i < v.size(); i++) {
		assert(v.getData()[i] == 7.0);
	}
	cout << "TEST DE LA MULTIPLICATION AVEC UN DOUBLE : OK" << endl;
}

void testDiviseDouble(){
	Dvector v(5,3.5);
	v /= 7.0;
	for (int i = 0; i < v.size(); i++) {
		assert(v.getData()[i] == 0.5);
	}
	cout << "TEST DE LA DIVISION AVEC UN DOUBLE : OK" << endl;
}

void testPlusDvector(){
	Dvector v1(100);
	Dvector v2(100);
	v1.fillRandomly();
	v2.fillRandomly();
	Dvector v1Initial(v1);
	v1 += v2;
	for (int i = 0; i < v1.size(); i++) {
		assert(v1.getData()[i] == (v1Initial.getData()[i] + v2.getData()[i]));
	}
	cout << "TEST DE L'ADDITION AVEC UN DVECTOR : OK" << endl;
}

void testMoinsDvector(){
	Dvector v1(100);
	Dvector v2(100);
	v1.fillRandomly();
	v2.fillRandomly();
	Dvector v1Initial(v1);
	v1 -= v2;
	for (int i = 0; i < v1.size(); i++) {
		assert(v1.getData()[i] == (v1Initial.getData()[i] - v2.getData()[i]));
	}
	cout << "TEST DE LA SOUSTRACTION AVEC UN DVECTOR : OK" << endl;
}

void testAffectation(){
	Dvector v1(100);
	Dvector v2(100);
	v2.fillRandomly();
	v1 = v2;
	for (int i = 0; i < v1.size(); i++) {
		assert(v1.getData()[i] == v2.getData()[i]);
	}
	cout << "TEST DE L'AFFECTATION : OK" << endl;
}

void testEgalite() {
	Dvector v1(3,5.);
	Dvector v2(3,5.);
	assert(v1 == v2);
	cout << "TEST DE L'EGALITE : OK" << endl;
}

void testInegaliteTaille() {
	Dvector v1(3,5.);
	Dvector v2(4,5.);
	assert(v1 != v2);
	cout << "PREMIER TEST DE L'INEGALITE (TAILLE DIFFERENTE) : OK" << endl;
}

void testInegaliteValeur() {
	Dvector v1(3,5.);
	Dvector v2(3,4.);
	assert(v1 != v2);
	cout << "SECOND TEST DE L'INEGALITE (VALEUR DIFFERENTE) : OK" << endl;
}

void testPlusDeuxDvector() {
	Dvector v1(100);
	Dvector v2(100);
	v1.fillRandomly();
	v2.fillRandomly();
	Dvector v(3);
	v = v1 + v2;
	for (int i = 0; i < v.size(); i++) {
		assert(v.getData()[i] == (v1.getData()[i] + v2.getData()[i]));
	}
	cout << "TEST DE L'ADDITION DE DEUX DVECTOR : OK" << endl;
}

void testMoinsDeuxDvector() {
	Dvector v1(100);
	Dvector v2(100);
	v1.fillRandomly();
	v2.fillRandomly();
	Dvector v(3);
	v = v1 - v2;
	for (int i = 0; i < v.size(); i++) {
		assert(v.getData()[i] == (v1.getData()[i] - v2.getData()[i]));
	}
	cout << "TEST DE LA SOUSTRACTION DE DEUX DVECTOR : OK" << endl;
}

void testOpposeDvector() {
	Dvector v1(100);
	v1.fillRandomly();
	Dvector v(3);
	v = -v1;
	for (int i = 0; i < v.size(); i++) {
		assert(v.getData()[i] == -v1.getData()[i]);
	}
	cout << "TEST DE L'OPPOSE D'UN DVECTOR : OK" << endl;
}

void testFluxSortant() {
	Dvector v(3,5.4);
	stringstream out;
	out << v;
	assert(out.str() == "5.4\n5.4\n5.4\n");
	cout << "TEST DU FLUX SORTANT : OK" << endl;
}

void testFluxEntrant() {
	Dvector vRef(3);
	Dvector v(3);
	vRef.fillRandomly();
	string file("testFluxEntrant.txt");
	fstream testFile(file.c_str());
	// On remplit le fichier avec vRef
	vRef.display(testFile);
	// On revient au début du fichier
	testFile.clear();
	testFile.seekg(0,testFile.beg);
	// On lit le fichier dans v
	testFile >> v;
	cout << vRef << endl;
	cout << v << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << "i = " << i << endl;
		cout << v.getData()[i] << " et " << vRef.getData()[i] << endl;
		assert(v.getData()[i] == vRef.getData()[i]);
		cout << i << " OK" << endl;
	}
	cout << "TEST DU FLUX ENTRANT : OK" << endl;
}
int main(){
	testParenthese();
	testPlusDouble();
	testMoinsDouble();
	testDiviseDouble();
	testPlusDvector();
	testMoinsDvector();
	testAffectation();
	testEgalite();
	testInegaliteTaille();
	testInegaliteValeur();
	testPlusDeuxDvector();
	testMoinsDeuxDvector();
	testOpposeDvector();
	testFluxSortant();
	testFluxEntrant();
}
