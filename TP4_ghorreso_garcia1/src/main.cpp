#include "Point.h"
#include "Triangle.h"
#include "Maillage.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cassert>
#include <sstream>
#include <vector>
using namespace std;

void testAffichage() {
	string file("testAffichageMaillage.dat");
	ofstream testFile(file.c_str());
	Maillage<double	, std::vector> m(7,5,Point<double>(0,0));
	testFile << m;
}

void testDeplacer() {
	string file("testDeplacer.dat");
	ofstream testFile(file.c_str());
	Maillage<double	, std::vector> m(7,5,Point<double>(0,0));
	m.deplacer(1,2);
	testFile << m;
}

void testRotation() {
	string file("testRotation.dat");
	ofstream testFile(file.c_str());
	Maillage<double	, std::vector> m(7,5,Point<double>(0,0));
	m.tourner(M_PI, Point<double>(0,0));
	testFile << m;
	string file2("testRotation2.dat");
	ofstream testFile2(file2.c_str());
	Maillage<double	, std::vector> m2(7,5,Point<double>(0,0));
	m2.tourner(M_PI/2.0, Point<double>(4,3));
	testFile2 << m2;
}

void testMaillageContr2() {
	string file("testMaillageConstr2.dat");
	ofstream testFile(file.c_str());
	Maillage<double	, std::vector> m(Point<double>(1,1), Point<double>(4,1),
			Point<double>(4,3), Point<double>(1,3), 12, 10);
	testFile << m;
}

void testFusion1() {
	string file("testFusion1.dat");
	ofstream testFile(file.c_str());
	Maillage<double, std::vector> m1(Point<double>(1,1), Point<double>(4,1),
			Point<double>(4,3), Point<double>(1,3), 12, 10);
	Maillage<double, std::vector> m2(Point<double>(1,3), Point<double>(4,3),
			Point<double>(4,6), Point<double>(1,6), 12, 5);
	m1.fusionner(m2);
	testFile << m1;
}
int main() {
	//testMaillageContr2();
	testFusion1();
}

