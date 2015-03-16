#include "Triangle.h"
#include <cassert>
#include <stdexcept>
#include <cmath>

template <typename T, template<typename,typename=std::allocator<Triangle<T> > > class C>
Maillage<T,C>::Maillage(int m, int n, const Point<T>& origine){
	fillMesh(m,1,n,1,origine);
}

template <typename T, template<typename,typename=std::allocator<Triangle<T> > > class C>
Maillage<T,C>::Maillage(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3,
				const Point<T>& p4, int m, int n) {
	T largeur = distance(p1,p2);
	T hauteur = distance(p1,p4);
	std::cout << largeur << std::endl;
	std::cout << m << std::endl;
	std::cout << hauteur << std::endl;
	std::cout << n << std::endl;
	T lStep = largeur/(T)m;
	T hStep = hauteur/(T)n;
	this->fillMesh(largeur,lStep,hauteur,hStep,p1);
	double angle = atan((p2.y()-p1.y())/(p2.x()-p1.x()));
	this->tourner(angle,p1);
}

template <typename T, template<typename,typename=std::allocator<Triangle<T> > > class C>
T Maillage<T,C>::distance(const Point<T>& p1, const Point<T>& p2){
	return sqrt(pow((p1.x()-p2.x()),2) + pow((p1.y()-p2.y()),2));
}

template <typename T, template<typename,typename=std::allocator<Triangle<T> > > class C>
void Maillage<T,C>::fillMesh(double largeur, double lStep, double hauteur, double hStep, const Point<T>& origine){
	if (lStep <= 0 || hStep <= 0)
		throw std::invalid_argument("m and n must not be negative");
	std::cout << lStep << std::endl;
	std::cout << hStep << std::endl;
	for(T i = origine.x() ; i < origine.x()+largeur ; i = i + lStep){
		for(T j = origine.y() ; j < origine.y()+hauteur ; j = j + hStep){
			(this->mesh).push_back(Triangle<T>(Point<T>(i,j),Point<T>(i,j+hStep),Point<T>(i+lStep,j)));
			(this->mesh).push_back(Triangle<T>(Point<T>(i+lStep,j+hStep),Point<T>(i,j+hStep),Point<T>(i+lStep,j)));
		}
	}
	this->p1 = Point<T>(origine);
	this->p2 = Point<T>(p1.x()+largeur, p1.y());
	this->p3 = Point<T>(p2.x(), p2.y() + hauteur);
	this->p4 = Point<T>(p1.x(), p3.y());
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
void Maillage<T,C>::transformer(double m11, double m12, double m21, double m22) {
	typename C< Triangle<T> >::iterator it;
	for (it = mesh.begin(); it != mesh.end(); it++) {
		it->transformer(m11,m12,m21,m22);
	}
	(this->p1).transformer(m11,m12,m21,m22);
	(this->p2).transformer(m11,m12,m21,m22);
	(this->p3).transformer(m11,m12,m21,m22);
	(this->p4).transformer(m11,m12,m21,m22);
}

template <typename T, template<typename,typename=std::allocator< Triangle<T> > > class C>
void Maillage<T,C>::deplacer(double dx, double dy) {
	typename C< Triangle<T> >::iterator it;
	for (it = mesh.begin(); it != mesh.end(); it++) {
		it->deplacer(dx,dy);
	}
	(this->p1).deplacer(dx,dy);
	(this->p2).deplacer(dx,dy);
	(this->p3).deplacer(dx,dy);
	(this->p4).deplacer(dx,dy);
}

template <typename T, template<typename,typename=std::allocator< Triangle<T> > > class C>
void Maillage<T,C>::tourner(double angle, const Point<T>& pt) {
	typename C< Triangle<T> >::iterator it;
	for (it = mesh.begin(); it != mesh.end(); it++) {
		it->tourner(angle, pt);
	}
	(this->p1).tourner(angle, pt);
	(this->p2).tourner(angle, pt);
	(this->p3).tourner(angle, pt);
	(this->p4).tourner(angle, pt);
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

