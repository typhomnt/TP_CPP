#include "Triangle.h"
#include <cassert>
#include <stdexcept>

template <typename T, template<typename,typename=std::allocator<Triangle<T> > > class C>
Maillage<T,C>::Maillage(int m, int n, const Point<T>& origine){
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			(this->mesh).push_back(Triangle<T>(Point<T>(i,j),Point<T>(i,j+1),Point<T>(i+1,j)));
			(this->mesh).push_back(Triangle<T>(Point<T>(i+1,j+1),Point<T>(i,j+1),Point<T>(i+1,j)));
		}
	} 
}

template <typename T, template< typename,typename=std::allocator< Triangle<T> > > class C>
typename C< Triangle<T> >::const_iterator Maillage<T,C>::beginiter() const{
	return (this->mesh).begin();
}

template <typename T, template<typename,typename=std::allocator< Triangle<T> > > class C>
typename C< Triangle<T> >::const_iterator Maillage<T,C>::enditer() const{
	return (this->mesh).end();
}

template <typename T, template<typename,typename=std::allocator< Triangle<T> > > class C>
void Maillage<T,C>::fusionner(const Maillage<T,C>& m){

 }

template <typename T, template<typename,typename=std::allocator< Triangle<T> > > class C>
std::ostream& operator<<(std::ostream& out, const Maillage<T,C>& m) {
	     for(typename C<Triangle<T> >::const_iterator it = m.beginiter() ; it != m.enditer() ; ++it){
	       out << (it->p1()).x() << " " << (it->p1()).y() <<  std::endl;
	       out << (it->p2()).x() << " " << (it->p2()).y() <<  std::endl;
	       out << (it->p3()).x() << " " << (it->p3()).y() <<  std::endl;
	       out << (it->p1()).x() << " " << (it->p1()).y() <<  std::endl;
	       out << std::endl;
	     }
	     return out;
}

