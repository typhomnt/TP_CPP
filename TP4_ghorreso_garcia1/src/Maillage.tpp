#include "Triangle.h"
#include <cassert>
#include <stdexcept>
#include <cmath>
#include <algorithm>

template <typename T, template<typename,typename=std::allocator<Triangle<T> > > class C>
Maillage<T,C>::Maillage(int m, int n, const Point<T>& origine){
	fillMesh(m,1,n,1,origine);
	this->m = m;
	this->n = n;
	this->lStep = 1.0;
	this->hStep = 1.0;
}

template <typename T, template<typename,typename=std::allocator<Triangle<T> > > class C>
Maillage<T,C>::Maillage(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3,
				const Point<T>& p4, int m, int n) {
	/* On verifie que les quatre points definissent bien un rectangle ie
	 * côtés opposés de même longueur et diagonales de même longueur
	 */
	if(abs(distance(p1,p4) - distance(p2,p3)) > pow(10,-8)
			|| abs(distance(p1,p2) - distance(p3,p4)) > pow(10,-8)
			|| abs(distance(p1,p3) - distance(p2,p4)) > pow(10,-8))
	   throw std::invalid_argument("the given points don't represent rectangle");
	T largeur = distance(p1,p2);
	T hauteur = distance(p1,p4);
	T lStep = largeur/(T)m;
	T hStep = hauteur/(T)n;
	std::cout << "hauteur = " << hauteur << std::endl;
	std::cout << "largeur = " << largeur << std::endl;
	std::cout << "hStep = " << hStep << std::endl;
	std::cout << "lStep = " << lStep << std::endl;
	this->fillMesh(m,lStep,n,hStep,p1);
	double angle = atan((p2.y()-p1.y())/(p2.x()-p1.x()));
	this->tourner(angle,p1);
	this->m = m;
	this->n = n;
	this->lStep = lStep;
	this->hStep = hStep;
}

template <typename T, template<typename,typename=std::allocator<Triangle<T> > > class C>
T Maillage<T,C>::distance(const Point<T>& p1, const Point<T>& p2){
	return sqrt(pow((p1.x()-p2.x()),2) + pow((p1.y()-p2.y()),2));
}

template <typename T, template<typename,typename=std::allocator<Triangle<T> > > class C>
void Maillage<T,C>::fillMesh(int m, double lStep, int n, double hStep, const Point<T>& origine){
	if (lStep <= 0 || hStep <= 0)
		throw std::invalid_argument("m and n must not be negative");
	T x = origine.x();
	T y = origine.y();
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			(this->mesh).push_back(Triangle<T>(Point<T>(x+i*lStep,y+j*hStep),
					Point<T>(x+i*lStep,y+(j+1)*hStep),Point<T>(x+(i+1)*lStep,y+j*hStep)));
			(this->mesh).push_back(Triangle<T>(Point<T>(x+(i+1)*lStep,y+(j+1)*hStep),
					Point<T>(x+i*lStep,y+(j+1)*hStep),Point<T>(x+(i+1)*lStep,y+j*hStep)));
		}
	}
	this->p1 = Point<T>(origine);
	this->p2 = Point<T>(p1.x()+m*lStep, p1.y());
	this->p3 = Point<T>(p2.x(), p2.y() + n*hStep);
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
     if(m.m != this->m && m.n != this->n)
    	throw std::invalid_argument("meshes must have at least m or n in cummon to be merged");
	if(m.lStep != this->lStep && m.hStep != this->hStep)
		throw std::invalid_argument("meshes must have at least lStep or hStep in cummon to be merged");
	if(this->xMax() > m.xMin() &&  this->xMin() < m.xMin() && this->yMin() < m.yMax() && this->yMax() > m.yMax())
		throw std::invalid_argument("meshes are overlapping each other");	
	// On doit trouver un côté en commun avec le même lStep ou hStep
	if(this->p4 == m.p1 && this->p3 == m.p2 && this->lStep == m.lStep){
		this->p4 = m.p4;
		this->p3 = m.p3;
	}  
	else if(this->p1 == m.p4 && this->p2 == m.p3 && this->lStep == m.lStep){
		this->p1 = m.p1;
		this->p2 = m.p2;
	}
 	else if (this->p1 == m.p2 && this->p4 == m.p3 && this->hStep == m.hStep){
 		this->p1 = m.p1;
 		this->p4 = m.p4;
	}
	else if(this->p2 == m.p1 && this->p3 == m.p4 && this->hStep == m.hStep) {
		this->p2 = m.p2;
		this->p3 = m.p3;
	} 
	else{
		throw std::invalid_argument("meshes are not compatible");	
	}
	//this->mesh.resize(this->mesh.size() + m.mesh.size());
	//std::merge(this->mesh.begin(),this->mesh.end(),m.beginiter(),m.enditer(),typename C< Triangle<T> >::ostream_iterator<T>(std::cout," "));
	std::cout << "fusion" << std::endl;
	this->concat(this->mesh, m.mesh);
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

template <typename T, template<typename,typename=std::allocator<Triangle<T> > > class C>
T Maillage<T,C>::xMax() const {
	T max = p1.x();
	if(p2.x() > max)
		max = p2.x();
	if(p3.x() > max)
		max = p3.x();
	if(p4.x() > max)
		max = p4.x();
	return max;
}

template <typename T, template<typename,typename=std::allocator<Triangle<T> > > class C>
T Maillage<T,C>::xMin() const {
	T min = p1.x();
	if(p2.x() < min)
		min = p2.x();
	if(p3.x() < min)
		min = p3.x();
	if(p4.x() < min)
		min = p4.x();
	return min;
}

template <typename T, template<typename,typename=std::allocator<Triangle<T> > > class C>
T Maillage<T,C>::yMax() const {
	T max = p1.y();
	if(p2.y() > max)
		max = p2.y();
	if(p3.y() > max)
		max = p3.y();
	if(p4.y() > max)
  	  max = p4.y();
	return max;
}

template <typename T, template<typename,typename=std::allocator<Triangle<T> > > class C>
T Maillage<T,C>::yMin() const {
    T min = p1.y();
    if(p2.y() < min)
    	min = p2.y();
    if(p3.y() < min)
    	min = p3.y();
    if(p4.y() < min)
    	min = p4.y();
    return min;
}

template <typename T, template<typename,typename=std::allocator<Triangle<T> > > class C>
void Maillage<T,C>::concat(C< Triangle<T> > mesh1, C< Triangle<T> > mesh2) {
	typename C< Triangle<T> >::iterator it;
	std::cout << "concat" << std::endl;
	mesh1.end() = mesh2.end();
	for (it = mesh2.begin(); it != mesh2.end(); it++) {
		mesh1.push_back(Triangle<T>(*it));
	}
}
