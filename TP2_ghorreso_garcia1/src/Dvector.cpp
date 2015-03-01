#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <cassert>
#include <stdexcept>
#include "Dvector.h"

Dvector::Dvector(){
    std::cout << "appel au constructeur par defaut" << std::endl;
    this->vect = NULL;
    this->sizeV = 0;
    this->isProp = true;
}

Dvector::Dvector(const int dim, const double val){
    std::cout << "appel au constructeur avec dimension et "
	"valeur initiale" << std::endl;
    this->vect = new double[dim];
    for(int i = 0; i < dim ; i++){
    	this->vect[i] = val;
    }
    this->sizeV = dim;
    this->isProp = true;
}

Dvector::Dvector(const Dvector& d){
    std::cout << "appel au constructeur par copie" << std::endl;
    this->sizeV = d.sizeV;
    this->isProp = d.isProp;
    this->vect = NULL;
    *this = d ;
}

Dvector::Dvector(const std::string file){
    std::cout << "appel au constructeur avec fichier" << std::endl;
    std::ifstream inputFile(file.c_str());
    this->isProp = true;
    if(inputFile){
    	int taille(0);
    	double buff;
    	// On calcule le nombre de reels dans le fichier
    	while(!inputFile.eof()){
	    inputFile >> buff;
	    taille++;
    	}
    	this->sizeV = taille - 1;
    	// On revient au debut du fichier
    	inputFile.clear();
    	inputFile.seekg(0,inputFile.beg);
    	this->vect = new double[this->sizeV];
    	int i(0);
    	while(!inputFile.eof()){
	    inputFile >> this->vect[i];
	    i++;
    	}
    }
    else {
    	this->vect = NULL;
	this->sizeV = 0;
    }
}

Dvector::~Dvector(){
    std::cout << "appel au destructeur" << std::endl;
    if(isProp)
    	delete [] vect;
}

void Dvector::display(std::ostream& str) const {
    if (this->sizeV == 0) {
    	str << "";
    } else {
    	for(int i = 0 ; i < this->sizeV ; i++)
    		str << this->vect[i] << std::endl;
    }
}

void Dvector::enter(std::istream& str) {
    for(int i = 0 ; i < this->sizeV ; i++)
    	str >> this->vect[i];
}

const double* Dvector::getData() const{
    return this->vect;
}

int Dvector::size() const{
    return this->sizeV;
}

bool Dvector::isOwner() const{
    return this->isProp;
}

void Dvector::fillRandomly(){
    static bool init = false;
    if (!init) { 
    	srand (time (NULL));
    	init = true;
    }
    double u;
    for(int i = 0; i < this->size(); i++){
    	u = (double)rand()/(double)RAND_MAX;
    	this->vect[i] = u;
    }
}

double& Dvector::operator()(const int i) const {
    assert(i >= 0 && i < this->size());
    return this->vect[i];
}


Dvector&  Dvector::operator+=(const double r){
    for(int i = 0 ; i < this->size() ; i++)
	this->vect[i] += r;
    return *this;
}

Dvector&  Dvector::operator-=(const double r){
    for(int i = 0 ; i < this->size() ; i++)
        this->vect[i] -= r;
    return *this;
}

Dvector&  Dvector::operator*=(const double r){
    for(int i = 0 ; i < this->size() ; i++)
        this->vect[i] *= r;
    return *this;
}

Dvector&  Dvector::operator/=(const double r){
    assert(r != 0);
    for(int i = 0 ; i < this->size() ; i++)
    	this->vect[i] /= r;
    return *this;
}

Dvector& Dvector::operator+=(const Dvector& d){
    assert(this->size() == d.sizeV);
    for(int i = 0 ; i < this->size() ; i++){
    	this->vect[i] += d.vect[i];
    }
    return *this;
}

Dvector& Dvector::operator-=(const Dvector& d){
    assert(this->size() == d.sizeV);
    for(int i = 0 ; i < this->size() ; i++){
    	this->vect[i] -= d.vect[i];
    }
    return *this;
}

Dvector& Dvector::operator=(const Dvector& d) {
    if(this->sizeV == 0){
    	this->isProp = d.isOwner();
    }
    else if(this->isProp == false && this->sizeV != d.sizeV){
    	throw std::exception();
    }
    if(this->sizeV > 0 && this->vect != NULL)
    	delete [] this->vect;
    this->sizeV = d.sizeV;
    if (!this->isProp) {
    	this->vect = d.vect;
    } else {
	this->vect = new double[d.sizeV];
	memcpy(this->vect, d.vect, d.sizeV*sizeof(double));
    }
    // L'état isProp ne change pas
    // Seconde implementation
    /*
      for (int i = 0; i < this->sizeV; i++)
      	  this->vect[i] = d.vect[i];
    */
    return *this;
}

bool Dvector::operator==(const Dvector& d) const {
    if(this->sizeV != d.sizeV)
    	return false;
    for(int i = 0 ; i < this->sizeV ; i++){
    	if(this->vect[i] != d.vect[i])
    		return false;
    }
    return true;
}

bool Dvector::operator!=(const Dvector& d) const {
    return !(*this == d);
}

Dvector operator+(const Dvector& d1, const Dvector& d2){
    assert(d1.size() == d2.size());
    Dvector res(d1);
    res += d2;
    return res;
}

Dvector operator-(const Dvector& d1, const Dvector& d2){
    assert(d1.size() == d2.size());
    Dvector res(d1);
    res -= d2;
    return res;
}

Dvector operator-(const Dvector& d){
    Dvector res(d);
    for(int i = 0 ; i < res.size() ; i ++){
    	res(i) = -res.getData()[i];
    }
    return res;
}

Dvector operator+(const Dvector& d, const double r){
    Dvector res(d);
    res += r ;
    return res;
}

Dvector operator-(const Dvector& d, const double r){
    Dvector res(d);
    res -= r ;
    return res;
}

Dvector operator*(const Dvector& d, const double r){
    Dvector res(d);
    res *= r ;
    return res;
}

Dvector operator/(const Dvector& d, const double r){
    Dvector res(d);
    res /= r ;
    return res;
}

Dvector operator+(const double r, const Dvector& d){
    Dvector res(d);
    return res + r ;
}

Dvector operator*(const double r, const Dvector& d){
    Dvector res(d);
    return res * r;
}

std::ostream& operator<<(std::ostream& out, const Dvector& d) {
    d.display(out);
    return out;
}

std::istream& operator>>(std::istream& in, Dvector& d) {
    d.enter(in);
    return in;
}

Dvector Dvector::view(bool copy, const int start, const int count) const {
    if(this->sizeV == 0)
    	throw std::logic_error("The Dvector must have a positive size");
    if(count == 0)
    	throw std::out_of_range("count must be positive");
    if(start < 0 || start + count > this->sizeV - 1)
    	throw std::out_of_range("start or (start + count) out of range");
    if(copy == true){
    	Dvector res1(count);
    	for(int i = 0 ; i < count ; i++)
    		res1.vect[i] = this->vect[i + start];
    	res1.isProp = true;
    	return res1;
    } 
    else {
	// Res.vect pointe vers l'élément d'indice start de this->vect
    	Dvector res2;
    	res2.vect = this->vect + start*sizeof(double)/8;
    	res2.isProp = false;
    	return res2;
    }
}

