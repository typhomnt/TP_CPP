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
	Maillage<double	, std::vector> m(7,5,Point<double>(1,1));
	testFile << m;
}

void testFlux() {
	Maillage<double	, std::vector> m(1,1,Point<double>(0,0));
	stringstream out;
	out << m;
	assert(out.str() == "0 0\n0 1\n1 0\n0 0\n\n1 1\n0 1\n1 0\n1 1\n\n");
	cout << "TEST DU FLUX SORTANT : OK" << endl;
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

void testMaillageContr2RectangleOblique() {
	string file("testMaillageConstr2RectangleOblique.dat");
	ofstream testFile(file.c_str());
	string file2("testMaillageConstr2RectangleOblique2.dat");
	ofstream testFile2(file2.c_str());
	Maillage<double	, std::vector> m(Point<double>(1,1), Point<double>(4,1),
			Point<double>(4,3), Point<double>(1,3), 12, 10);
	testFile << m;
	m.tourner(M_PI/4, Point<double>(2,2));
	Maillage<double, std::vector> m2(m.point1(), m.point2(), m.point3(), m.point4(), 6, 5);
	testFile2 << m2;
}

void testMaillageContr2RectangleOblique2() {
	string file("testMaillageConstr2Rec.dat");
	ofstream testFile(file.c_str());
	Maillage<double	, std::vector> m(Point<double>(2,3), Point<double>(5,6),
			Point<double>(3,8), Point<double>(0,5), 2, 3);
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

void testFusion2() {
	string file("testFusion2.dat");
	ofstream testFile(file.c_str());
	Maillage<double, std::vector> m1(Point<double>(1,1), Point<double>(4,1),
			Point<double>(4,3), Point<double>(1,3), 12, 10);
	Maillage<double, std::vector> m2(Point<double>(4,1), Point<double>(6,1),
			Point<double>(6,3), Point<double>(4,3), 6, 10);
	m1.fusionner(m2);
	Maillage<double, std::vector> m3(Point<double>(6,1), Point<double>(10,1),
			Point<double>(10,3), Point<double>(6,3), 8, 10);
	m1.fusionner(m3);
	testFile << m1;
}

void testFusionException() {
	Maillage<double, std::vector> m1(Point<double>(1,1), Point<double>(4,1),
			Point<double>(4,3), Point<double>(1,3), 12, 10);
	Maillage<double, std::vector> m2(Point<double>(4,1), Point<double>(6,1),
			Point<double>(6,4), Point<double>(4,4), 6, 10);
	try {
		m1.fusionner(m2);
	} catch (std::invalid_argument const& e) {
		cout << "TEST DE LA FUSION (COTES ADJACENTS MAIS PAS EGAUX): OK" << std::endl;
	}
}

void testFusionException2() {
	Maillage<double, std::vector> m1(Point<double>(1,1), Point<double>(4,1),
			Point<double>(4,3), Point<double>(1,3), 12, 10);
	Maillage<double, std::vector> m2(Point<double>(4,1), Point<double>(6,1),
			Point<double>(6,3), Point<double>(4,3), 12, 5);
	try {
		m1.fusionner(m2);
	} catch (std::invalid_argument const& e) {
		cout << "TEST DE LA FUSION (HSTEP DIFFERENT): OK" << std::endl;
	}
}

void testFusionException3() {
	Maillage<double, std::vector> m1(Point<double>(1,1), Point<double>(4,1),
			Point<double>(4,3), Point<double>(1,3), 12, 10);
	Maillage<double, std::vector> m2(Point<double>(2,2), Point<double>(5,2),
			Point<double>(5,4), Point<double>(2,4), 12, 10);
	try {
		m1.fusionner(m2);
	} catch (std::invalid_argument const& e) {
		cout << "TEST DE LA FUSION (RECOUVREMENT): OK" << std::endl;
	}
}

void testFusionException4() {
	Maillage<double, std::vector> m1(Point<double>(1,1), Point<double>(4,1),
			Point<double>(4,3), Point<double>(1,3), 12, 10);
	Maillage<double, std::vector> m2(Point<double>(6,1), Point<double>(10,1),
			Point<double>(10,3), Point<double>(6,3), 12, 10);
	try {
		m1.fusionner(m2);
	} catch (std::invalid_argument const& e) {
	cout << "TEST DE LA FUSION (PAS ADJACENTS): OK" << std::endl;
	}
}

void testFusionException5() {
	Maillage<double, std::vector> m1(Point<double>(1,1), Point<double>(4,1),
			Point<double>(4,3), Point<double>(1,3), 12, 10);
	Maillage<double, std::vector> m2(Point<double>(2,1), Point<double>(4,1),
			Point<double>(4,3), Point<double>(2,3), 12, 10);
	try {
		m1.fusionner(m2);
	} catch (std::invalid_argument const& e) {
	cout << "TEST DE LA FUSION (ADJACENTS MAIS RECOUVREMENT): OK" << std::endl;
	}
}

void testFusionException6() {
	Maillage<double, std::vector> m1(Point<double>(1,1), Point<double>(4,1),
			Point<double>(4,3), Point<double>(1,3), 12, 10);
	Maillage<double, std::vector> m2(Point<double>(1,3), Point<double>(4,3),
			Point<double>(4,6), Point<double>(1,6), 6, 5);
	try {
		m1.fusionner(m2);
	} catch (std::invalid_argument const& e) {
	cout << "TEST DE LA FUSION (LSTEP DIFFERENT): OK" << std::endl;
	}
}

void testTransformer() {
	string file("testTransformer.dat");
	ofstream testFile(file.c_str());
	string file2("testTransformer2.dat");
	ofstream testFile2(file2.c_str());
	Maillage<double, std::vector> m1(Point<double>(1,1), Point<double>(4,1),
			Point<double>(4,3), Point<double>(1,3), 12, 10);
	testFile2 << m1;
	m1.transformer(0.5, 0, 0, 0.5);
	testFile << m1;
	m1.display();
}

void testConstr2Exception() {
	try {
		Maillage<double, std::vector> m1(Point<double>(1,1), Point<double>(4,1),
				Point<double>(4,3), Point<double>(1,4), 12, 10);
	} catch (std::invalid_argument const& e) {
		cout << "TEST DU CONSTRUCTEUR 2 (COTES PAS EGAUX) : OK" << std::endl;
	}
}

void testConstr2Exception2() {
	try {
		Maillage<double, std::vector> m1(Point<double>(1,1), Point<double>(2,4),
				Point<double>(1,7), Point<double>(0,4), 12, 10);
		m1.display();
	} catch (std::invalid_argument const& e) {
		cout << "TEST DU CONSTRUCTEUR 2 (DIAGONALES PAS EGALES) : OK" << std::endl;
	}
}
int main() {
	//testMaillageContr2();
	//testFusion1();
	//testTransformer();
	//testConstr2Exception();
	//testConstr2Exception2();
//	testAffichage();
//	testFlux();
//	testMaillageContr2RectangleOblique();
//	testMaillageContr2RectangleOblique2();
//	testFusion2();
	testFusionException();
	testFusionException2();
	testFusionException3();
	testFusionException4();
	testFusionException5();
	testFusionException6();
}

