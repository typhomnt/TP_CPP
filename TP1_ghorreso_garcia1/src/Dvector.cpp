#include <iostream>
#include <fstream>
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
