#ifndef POINTH
#define POINTH
#include <iostream>
#include <istream>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @file Point.h
 *
 * Classe representant les points bidimensionnels
 */

template <typename T>
class Point {
private:

	T abs;
	T ord;

public:

	Point();
	Point(const T abs, const T ord);
	Point(const Point<T>& p);
	T x() const;
	T y() const;
	void transformer(double m11, double m12, double m21, double m22);
	void deplacer(double dx, double dy);
	void tourner(double angle, const Point<T>& pt);
};

#include "Point.tpp"
#endif
