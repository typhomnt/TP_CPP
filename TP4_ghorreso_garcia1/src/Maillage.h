#ifndef MAILLAGEH
#define MAILLAGEH
#include <iostream>
#include <istream>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Triangle.h"

template <typename T, template<typename,typename=std::allocator<T> > class C>
	class Maillage {
 private:
 
	C<Triangle<T> > mesh;
 
 public:
 Maillage(int m, int n, const Point<T>& origine);
 typename C<Triangle<T> >::const_iterator beginiter() const;
 typename C<Triangle<T> >::const_iterator enditer() const;
 void fusionner(const Mailllage<T,C>& m);

};
template <typename T,template<typename,typename=std::allocator<T>  > class C>
	std::ostream& operator<<(std::ostream& out, const Maillage<T,C>& m);


#include "Maillage.tpp"
#endif
