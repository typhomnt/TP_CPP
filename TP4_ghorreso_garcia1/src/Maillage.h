#ifndef MAILLAGEH
#define MAILLAGEH
#include <iostream>
#include <istream>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Triangle.h"
#include "Point.h"

template <typename T, template< typename,typename=std::allocator< Triangle<T> > > class C>
class Maillage {
	private:
 
		C< Triangle<T> > mesh;
		Point<T> p1;
		Point<T> p2;
		Point<T> p3;
		Point<T> p4;

		T distance(const Point<T>& p1, const Point<T>& p2);
		void fillMesh(double m, double mStep, double n, double nStep, const Point<T>& origine);
 
	public:

		Maillage(int m, int n, const Point<T>& origine);
		Maillage(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3,
				const Point<T>& p4, int m, int n);
		typename C< Triangle<T> >::const_iterator beginiter() const;
		typename C< Triangle<T> >::const_iterator enditer() const;
		void fusionner(const Maillage<T,C>& m);
		void transformer(double m11, double m12, double m21, double m22);
		void deplacer(double dx, double dy);
		void tourner(double angle, const Point<T>& pt);

};

template <typename T, template< typename,typename=std::allocator< Triangle<T> > > class C>
std::ostream& operator<<(std::ostream& out, const Maillage<T,C>& m);


#include "Maillage.tpp"
#endif
