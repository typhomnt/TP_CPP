#include "Point.h"
#include <cassert>
#include <stdexcept>

template <typename Type>
Triangle<Type>::Triangle() {
	this->a = Point<Type>();
	this->b = Point<Type>();
	this->c = Point<Type>();
}

template <typename Type>
Triangle<Type>::Triangle(const Point<Type> & a, const Point<Type> & b, const Point<Type> & c) {
	this->a = Point<Type>(a);
	this->b = Point<Type>(b);
	this->c = Point<Type>(c);
}

template <typename Type>
Triangle<Type>::Triangle(const Triangle & t) {
	this->a = Point<Type>(t.a);
	this->b = Point<Type>(t.b);
	this->c = Point<Type>(t.c);
}

template <typename Type>
Point<Type>& Triangle<Type>::p1() {
	return this->a;
}

template <typename Type>
Point<Type>& Triangle<Type>::p2() {
	return this->b;
}

template <typename Type>
Point<Type>& Triangle<Type>::p3() {
	return this->c;
}
