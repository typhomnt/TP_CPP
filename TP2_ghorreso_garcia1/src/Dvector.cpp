#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <cassert>
#include "Dvector.h"

Dvector::Dvector(){
    std::cout << "appel au constructeur par defaut" << std::endl;
    this->vect = NULL;
    this->sizeV = 0;
}

Dvector::Dvector(int dim, double val){
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
    this->vect = new double[d.sizeV];
    for(int i = 0; i < d.sizeV ; i++){
	this->vect[i] = d.vect[i];
    }
    this->sizeV = d.sizeV;
    this->isProp = d.isProp;
}

Dvector::Dvector(std::string file){
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
    delete [] vect;
}

void Dvector::display(std::ostream& str) const {
    for(int i = 0 ; i < this->sizeV ; i++)
    	str << this->vect[i] << std::endl;
}

void Dvector::enter(std::istream& str) const {
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
    srand (time (NULL));
    double u;
    for(int i = 0; i < this->size(); i++){
    	u = (double)rand()/(double)RAND_MAX;
    	this->vect[i] = u;
    }
}

double& Dvector::operator()(int i){
    assert(i >= 0 && i < this->size());
    return this->vect[i];
}


Dvector&  Dvector::operator+=(double r){
    for(int i = 0 ; i < this->size() ; i++)
	   this->vect[i] += r;
    return *this;
}

Dvector&  Dvector::operator-=(double r){
    for(int i = 0 ; i < this->size() ; i++)
        this->vect[i] -= r;
    return *this;
}

Dvector&  Dvector::operator*=(double r){
    for(int i = 0 ; i < this->size() ; i++)
        this->vect[i] *= r;
    return *this;
}

Dvector&  Dvector::operator/=(double r){
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
	delete [] this->vect;
	this->vect = new double[d.sizeV];
	this->sizeV = d.sizeV;
	memcpy(this->vect, d.vect, d.sizeV*sizeof(double));
	return *this;
}

bool Dvector::operator==(const Dvector& d){
	if(this->sizeV != d.sizeV)
		return false;
	for(int i = 0 ; i < this->sizeV ; i++){
		if(this->vect[i] != d.vect[i])
			return false;
	}
	return true;
}

bool Dvector::operator!=(const Dvector& d){
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

std::ostream& operator<<(std::ostream& out, const Dvector& d) {
	d.display(out);
	return out;
}

std::istream& operator>>(std::istream& in, const Dvector& d) {
	d.enter(in);
	return in;
}

Dvector Dvector::view(bool copy, int start, int count){
	if(this->sizeV == 0)
		throw std::exception();
	if(count == 0)
		throw std::exception();
	if(start < 0 || start + count > this->sizeV - 1)
		throw std::exception();
	Dvector res(count);
	if(copy == true){
		for(int i = 0 ; i < count ; i++)
			res.vect[i] = this->vect[i + start];
		res.isProp = false;
		return res;
	} 
	else {
		res.vect = this->vect + start*sizeof(double);
		res.isProp = false;
		return res;
	}
}

int main(){
  Dvector d(3,1.);
  Dvector d2(4,5.);
  Dvector d3(4,5.);
  assert(d2 == d3);
  assert(d != d2);
  //std::cout << "entrez 3 valeurs";
  //std::cin >> d;
  //std::cout << d;
  (-d2).display(std::cout);
}
