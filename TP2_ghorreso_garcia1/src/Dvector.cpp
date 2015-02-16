#include <iostream>
#include <fstream>
#include <cassert>
#include "Dvector.h"

Dvector::Dvector(){
    std::cout << "appel au constructeur par defaut" << std::endl;
    this->vect = new double[1];
    this->vect[0] = 0.0;
    this->sizeV = 1;
}

Dvector::Dvector(int dim, double val){
    std::cout << "appel au constructeur avec dimension et "
	"valeur initiale" << std::endl;
    this->vect = new double[dim];
    for(int i = 0; i < dim ; i++){
	this->vect[i] = val;
    }
    this->sizeV = dim;
}

Dvector::Dvector(const Dvector& d){
    std::cout << "appel au constructeur par copie" << std::endl;
    this->vect = new double[d.sizeV];
    for(int i = 0; i < d.sizeV ; i++){
	this->vect[i] = d.vect[i];
    }
    this->sizeV = d.sizeV;
}

Dvector::Dvector(std::string file){
    std::cout << "appel au constructeur avec fichier" << std::endl;
    std::ifstream inputFile(file.c_str());
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

void Dvector::display(std::ostream& str){
    for(int i = 0 ; i < this->sizeV ; i++)
	str << this->vect[i] << std::endl;
}

double* Dvector::getVect(){
    return this->vect;
}

int Dvector::size(){
    return this->sizeV;
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

Dvector operator+(const Dvector& d1, const Dvector& d2){
	//assert(((Dvector)d1).size() == ((Dvector)d2).size());
	Dvector res(d1);
	res += d2;
	return res;
}

Dvector operator-(const Dvector& d1, const Dvector& d2){
	//assert(((Dvector)d1).size() == ((Dvector)d2).size());
	Dvector res(d1);
	res -= d2;
	return res;
}

Dvector operator-(const Dvector& d){
	Dvector res(d);
	for(int i = 0 ; i < res.size() ; i ++){
		res.getVect()[i] = -res.getVect()[i];
	}
	return res;
}

Dvector& Dvector::operator=(const Dvector& d) {
	delete [] this->vect;
	this->vect = new double[d.sizeV];
	this->sizeV = d.sizeV;
	memcpy(this->vect, d.vect, d.sizeV*sizeof(double));
	return *this;
}

int main(){
  Dvector d(3,1.);
  Dvector d2(4,5.);
  Dvector d3(4,2.);
  d = -d3;
  d.display(std::cout);
 }
