#ifndef TRIANGLEH
#define TRIANGLEH
#include <iostream>
#include <istream>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Point.h"

template <typename Type>
class Triangle {
private:

	Point<Type> a;
	Point<Type> b;
	Point<Type> c;

public:
	Triangle();
	Triangle(const Point<Type>& a, const Point<Type>& b, const Point<Type>& c);
	Triangle(const Triangle<Type>& t);

	const Point<Type>& p1() const;
	const Point<Type>& p2() const;
	const Point<Type>& p3() const;

	void transformer(double m11, double m12, double m21, double m22);
	void deplacer(double dx, double dy);
	void tourner(double angle, const Point<Type>& pt);
};

#include "Triangle.tpp"
#endif
