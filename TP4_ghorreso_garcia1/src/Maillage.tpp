#include "Triangle.h"
#include <cassert>
#include <stdexcept>

template <typename T,template<typename,typename=std::allocator<T>  > class C>
Maillage<T,C>::Maillage(int m, int n, const Point<T>& origine){
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			(this->mesh).push_back(Triangle<T>(Point<T>(i,j),Point<T>(i+1,j),Point<T>(i+1,j+1)));
			(this->mesh).push_back(Triangle<T>(Point<T>(i,j),Point<T>(i,j+1),Point<T>(i+1,j+1)));
		}
	} 
}

template <typename T,template<typename,typename=std::allocator<T>  > class C>
 typename C<Triangle<T> >::const_iterator& Maillage<T,C>::beginiter(){
}

template <typename T,template<typename,typename=std::allocator<T>  > class C>
 typename C<Triangle<T> >::const_iterator& Maillage<T,C>::enditer(){
}

std::ostream& operator<<(std::ostream& out, const Maillage& m) {
}