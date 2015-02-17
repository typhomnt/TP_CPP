#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

void testDvectorConstr1() {
	Dvector v;
	assert(v.size() == 0);
	assert(v.getData() == NULL);
	assert(v.isOwner() == true);
	cout << "TEST DU CONSTRUCTEUR PAR DEFAUT : OK" << endl;
}

void testDvectorConstr2() {
	Dvector v(2, 3.5);
	assert(v.size() == 2);
	stringstream str;
	v.display(str);
	assert(str.str() == "3.5\n3.5\n");
	assert(v.isOwner() == true);
	cout << "TEST DU CONTRUCTEUR AVEC INITIALISATION: OK" << endl;
}

void testDvectorConstr3() {
	Dvector v(5, 6.4);
	Dvector copie(v);
	stringstream str_v, str_copie;
	v.display(str_v);
	copie.display(str_copie);
	assert(str_v.str() == str_copie.str());
	assert(copie.isOwner() == v.isOwner());
	cout << "TEST DU CONTRUCTEUR PAR COPIE : OK" << endl;
}

void testDvectorConstrFile(){
	Dvector ref(100,0.2);
	ref.fillRandomly();
	string file("test4.txt");
	ofstream testFile(file.c_str());
	ref.display(testFile);
	Dvector vt("test4.txt");
	stringstream str_ref, str_vt;
	ref.display(str_ref);
	vt.display(str_vt);
	assert(str_ref.str() == str_vt.str());
	assert(vt.isOwner() == true);
	cout << "TEST DU CONSTRUCTEUR AVEC FICHIER : OK" << endl;
}

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

void testAffectationMemeTaille1() {
	cout << "cas 1" << endl;
	Dvector a(100);
	cout << "a.isProp = " << a.isOwner() << endl;
	Dvector b(100);
	b.fillRandomly();
	a = b;
	for (int i = 0; i < a.size(); i++) {
		assert(a.getData()[i] == b.getData()[i]);
	}
	assert(a.isOwner() == true);
	cout << "b.isProp = " << b.isOwner() << endl;
	cout << "TEST DE L'AFFECTATION D'UN DVECTOR DE MEME TAILLE (CAS 1) : OK" << endl;
}

void testAffectationMemeTaille2() {
	cout << "cas 2" << endl;
	Dvector a(100);
	cout << "a.isProp = " << a.isOwner() << endl;
	Dvector c(150);
	c.fillRandomly();
	Dvector b(c.view(true, 0, 100));
	a = b;
	for (int i = 0; i < a.size(); i++) {
		assert(a.getData()[i] == b.getData()[i]);
	}
	assert(a.isOwner() == true);
	cout << "b.isProp = " << b.isOwner() << endl;
	cout << "TEST DE L'AFFECTATION D'UN DVECTOR DE MEME TAILLE (CAS 2) : OK" << endl;
}

void testAffectationMemeTaille3() {
	cout << "cas 3" << endl;
	Dvector b(100);
	Dvector c(150);
	c.fillRandomly();
	Dvector a(c.view(true, 0, 100));
	cout << "a.isProp = " << a.isOwner() << endl;
	a = b;
	for (int i = 0; i < a.size(); i++) {
		assert(a.getData()[i] == b.getData()[i]);
	}
	assert(a.isOwner() == false);
	cout << "b.isProp = " << b.isOwner() << endl;
	cout << "TEST DE L'AFFECTATION D'UN DVECTOR DE MEME TAILLE (CAS 3) : OK" << endl;
}

void testAffectationMemeTaille4() {
	cout << "cas 4" << endl;
	Dvector c(150);
	Dvector d(200);
	c.fillRandomly();
	d.fillRandomly();
	Dvector a(c.view(true, 0, 100));
	cout << "a.isProp = " << a.isOwner() << endl;
	Dvector b(d.view(true, 0, 100));
	a = b;
	for (int i = 0; i < a.size(); i++) {
		assert(a.getData()[i] == b.getData()[i]);
	}
	assert(a.isOwner() == false);
	cout << "b.isProp = " << b.isOwner() << endl;
	cout << "TEST DE L'AFFECTATION D'UN DVECTOR DE MEME TAILLE (CAS 4) : OK" << endl;
}

void testAffectationMemeTaille5() {
	cout << "cas 5" << endl;
	Dvector a;
	cout << "a.size = " << a.size() << endl;
	Dvector b(100);
	a = b;
	for (int i = 0; i < a.size(); i++) {
		assert(a.getData()[i] == b.getData()[i]);
	}
	assert(a.isOwner() == true);
	cout << "b.isProp = " << b.isOwner() << endl;
	cout << "TEST DE L'AFFECTATION D'UN DVECTOR DE MEME TAILLE (CAS 5) : OK" << endl;
}

void testAffectationMemeTaille6() {
	cout << "cas 6" << endl;
	Dvector a;
	cout << "a.size = " << a.size() << endl;
	Dvector c(150);
	c.fillRandomly();
	Dvector b(c.view(true, 0, 100));
	a = b;
	for (int i = 0; i < a.size(); i++) {
		assert(a.getData()[i] == b.getData()[i]);
	}
	assert(a.isOwner() == false);
	cout << "b.isProp = " << b.isOwner() << endl;
	cout << "TEST DE L'AFFECTATION D'UN DVECTOR DE MEME TAILLE (CAS 6) : OK" << endl;
}

void testAffectationTailleDifferente1() {
	cout << "cas 1" << endl;
	Dvector a(100);
	cout << "a.isProp = " << a.isOwner() << endl;
	Dvector b(50);
	b.fillRandomly();
	a = b;
	for (int i = 0; i < a.size(); i++) {
		assert(a.getData()[i] == b.getData()[i]);
	}
	assert(a.isOwner() == true);
	cout << "b.isProp = " << b.isOwner() << endl;
	cout << "TEST DE L'AFFECTATION D'UN DVECTOR DE TAILLE DIFFERENTE (CAS 1) : OK" << endl;
}

void testAffectationTailleDifferente2() {
	cout << "cas 2" << endl;
	Dvector a(100);
	cout << "a.isProp = " << a.isOwner() << endl;
	Dvector c(150);
	c.fillRandomly();
	Dvector b(c.view(true, 0, 50));
	a = b;
	for (int i = 0; i < a.size(); i++) {
		assert(a.getData()[i] == b.getData()[i]);
	}
	assert(a.isOwner() == true);
	cout << "b.isProp = " << b.isOwner() << endl;
	cout << "TEST DE L'AFFECTATION D'UN DVECTOR DE TAILLE DIFFERENTE (CAS 2) : OK" << endl;
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
		assert(v.getData()[i] == vRef.getData()[i]);
	}
	cout << "TEST DU FLUX ENTRANT : OK" << endl;
}

int main(){
	/*testParenthese();
	testPlusDouble();
	testMoinsDouble();
	testDiviseDouble();
	testPlusDvector();
	testMoinsDvector();
	testEgalite();
	testInegaliteTaille();
	testInegaliteValeur();
	testPlusDeuxDvector();
	testMoinsDeuxDvector();
	testOpposeDvector();
	testFluxSortant();
	testFluxEntrant();
	testDvectorConstr1();
	testDvectorConstr2();
	testDvectorConstr3();
	testDvectorConstrFile();
	testAffectationMemeTaille1();
	testAffectationMemeTaille2();
	testAffectationMemeTaille3();
	testAffectationMemeTaille4();
	testAffectationMemeTaille5();
	testAffectationMemeTaille6();
	testAffectationTailleDifferente1();
	testAffectationTailleDifferente2()*/;
}
