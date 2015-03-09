#include <fstream>
#include <cassert>
#include <stdexcept>

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
