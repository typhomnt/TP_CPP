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
const Point<Type>& Triangle<Type>::p1() const{
	return this->a;
}

template <typename Type>
const Point<Type>& Triangle<Type>::p2() const{
	return this->b;
}

template <typename Type>
const Point<Type>& Triangle<Type>::p3() const{
	return this->c;
}

template <typename Type>
void Triangle<Type>::transformer(double m11, double m12, double m21, double m22) {
	(this->a).transformer(m11,m12,m21,m22);
	(this->b).transformer(m11,m12,m21,m22);
	(this->c).transformer(m11,m12,m21,m22);
}

template <typename Type>
void Triangle<Type>::deplacer(double dx, double dy) {
	(this->a).deplacer(dx,dy);
	(this->b).deplacer(dx,dy);
	(this->c).deplacer(dx,dy);
}

template <typename Type>
void Triangle<Type>::tourner(double angle, const Point<Type>& pt) {
	(this->a).tourner(angle, pt);
	(this->b).tourner(angle, pt);
	(this->c).tourner(angle, pt);
}
