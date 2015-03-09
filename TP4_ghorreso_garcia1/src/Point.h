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
};

#include "Point.tpp"
#endif
