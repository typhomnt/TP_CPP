#include <fstream>
#include <cassert>
#include <stdexcept>
#include <cmath>

template <typename T>
Point<T>::Point() {
	this->abs = 0.0;
	this->ord = 0.0;
}

template <typename T>
Point<T>::Point(const T abs, const T ord) {
	this->abs = abs;
	this->ord = ord;
}

template <typename T>
Point<T>::Point(const Point<T>& p) {
	this->abs = p.abs;
	this->ord = p.ord;
}

template <typename T>
T Point<T>::x() const {
	return this->abs;
}

template <typename T>
T Point<T>::y() const {
	return this->ord;
}

template <typename T>
void Point<T>::transformer(double m11, double m12, double m21, double m22) {
	T temp = this->abs;
	this->abs = temp*m11 + this->ord*m21;
	this->ord = temp*m12 + this->ord*m22;
}

template <typename T>
void Point<T>::deplacer(double dx, double dy) {
	this->abs = this->abs + dx;
	this->ord = this->ord + dy;
}

template <typename T>
void Point<T>::tourner(double angle, const Point<T>& pt) {
	this->deplacer(-pt.abs,-pt.ord);
	this->transformer(cos(angle), sin(angle), -sin(angle), cos(angle));
	this->deplacer(pt.abs,pt.ord);
}

template <typename T>
bool Point<T>::operator==(const Point<T> p) {
	return this->abs == p.abs && this->ord == p.ord;
}
