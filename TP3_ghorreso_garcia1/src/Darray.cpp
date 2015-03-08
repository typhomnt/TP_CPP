#include "Darray.h"
#include <fstream>
#include <cassert>
#include <stdexcept>

Darray::Darray() {
	std::cout << "appel au constructeur par defaut" << std::endl;
	this->data = NULL;
	this->sizeD = 0;
	this->isProp = true;
}

Darray::Darray(const int dim, const double val){
    std::cout << "appel au constructeur avec dimension et "
	"valeur initiale" << std::endl;
    this->data = new double[dim];
    for(int i = 0; i < dim ; i++){
    	this->data[i] = val;
    }
    this->sizeD = dim;
    this->isProp = true;
}

Darray::Darray(const Darray& d){
    std::cout << "appel au constructeur par copie" << std::endl;
    this->sizeD = d.sizeD;
    this->isProp = d.isProp;
    this->data = NULL;
    *this = d ;
}

Darray::Darray(const std::string file){
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
    	this->sizeD = taille - 1;
    	// On revient au debut du fichier
    	inputFile.clear();
    	inputFile.seekg(0,inputFile.beg);
    	this->data = new double[this->sizeD];
    	int i(0);
    	while(!inputFile.eof()){
    		inputFile >> this->data[i];
    		i++;
    	}
    }
    else {
    	this->data = NULL;
    	this->sizeD = 0;
    }
}

Darray::~Darray(){
    std::cout << "appel au destructeur" << std::endl;
    if(isProp)
    	delete [] data;
}

void Darray::display(std::ostream& str) const {
    if (this->sizeD == 0) {
    	str << "";
    } else {
    	for(int i = 0 ; i < this->sizeD ; i++)
    		str << this->data[i] << std::endl;
    }
}

const double* Darray::getData() const{
    return this->data;
}

int Darray::size() const{
    return this->sizeD;
}

bool Darray::isOwner() const{
    return this->isProp;
}

void Darray::fillRandomly(){
    static bool init = false;
    if (!init) {
    	srand (time (NULL));
    	init = true;
    }
    double u;
    for(int i = 0; i < this->size(); i++){
    	u = (double)rand()/(double)RAND_MAX;
    	this->data[i] = u;
    }
}

double& Darray::operator()(const int i) const {
    assert(i >= 0 && i < this->size());
    return this->data[i];
}

Darray&  Darray::operator+=(const double r){
    for(int i = 0 ; i < this->size() ; i++)
    	this->data[i] += r;
    return *this;
}

Darray&  Darray::operator-=(const double r){
    for(int i = 0 ; i < this->size() ; i++)
        this->data[i] -= r;
    return *this;
}

Darray&  Darray::operator*=(const double r){
    for(int i = 0 ; i < this->size() ; i++)
        this->data[i] *= r;
    return *this;
}

Darray&  Darray::operator/=(const double r){
    assert(r != 0);
    for(int i = 0 ; i < this->size() ; i++)
    	this->data[i] /= r;
    return *this;
}

Darray& Darray::operator+=(const Darray& d){
    assert(this->size() == d.sizeD);
    for(int i = 0 ; i < this->size() ; i++){
    	this->data[i] += d.data[i];
    }
    return *this;
}

Darray& Darray::operator-=(const Darray& d){
    assert(this->size() == d.sizeD);
    for(int i = 0 ; i < this->size() ; i++){
    	this->data[i] -= d.data[i];
    }
    return *this;
}

Darray& Darray::operator=(const Darray& d) {
    if(this->sizeD == 0){
    	this->isProp = d.isOwner();
    } else if(this->isProp == false && this->sizeD != d.sizeD){
    	throw std::exception();
    }
    if(this->sizeD > 0 && this->data != NULL)
    	delete [] this->data;
    this->sizeD = d.sizeD;
    if (!this->isProp) {
    	this->data = d.data;
    } else {
    	this->data = new double[d.sizeD];
    	memcpy(this->data, d.data, d.sizeD*sizeof(double));
    }
    // L'état isProp ne change pas
    // Seconde implementation
    /*
      for (int i = 0; i < this->sizeD; i++)
      	  this->data[i] = d.data[i];
    */
    return *this;
}

bool Darray::operator==(const Darray& d) const {
    if(this->sizeD != d.sizeD)
    	return false;
    for(int i = 0 ; i < this->sizeD ; i++){
    	if(this->data[i] != d.data[i])
    		return false;
    }
    return true;
}

bool Darray::operator!=(const Darray& d) const {
    return !(*this == d);
}

Darray operator+(const Darray& d1, const Darray& d2){
    assert(d1.size() == d2.size());
    Darray res(d1);
    res += d2;
    return res;
}

Darray operator-(const Darray& d1, const Darray& d2){
    assert(d1.size() == d2.size());
    Darray res(d1);
    res -= d2;
    return res;
}

Darray operator-(const Darray& d){
    Darray res(d);
    for(int i = 0 ; i < res.size() ; i ++){
    	res(i) = -res.getData()[i];
    }
    return res;
}

Darray operator+(const Darray& d, const double r){
    Darray res(d);
    res += r ;
    return res;
}

Darray operator-(const Darray& d, const double r){
    Darray res(d);
    res -= r ;
    return res;
}

Darray operator*(const Darray& d, const double r){
    Darray res(d);
    res *= r ;
    return res;
}

Darray operator/(const Darray& d, const double r){
	assert(r != 0);
    Darray res(d);
    res /= r ;
    return res;
}

Darray operator+(const double r, const Darray& d){
    Darray res(d);
    return res + r ;
}

Darray operator*(const double r, const Darray& d){
    Darray res(d);
    return res * r;
}

Darray Darray::view(bool copy, const int start, const int count) const {
    if(this->sizeD == 0)
    	throw std::logic_error("The Darray must have a positive size");
    if(count == 0)
    	throw std::out_of_range("count must be positive");
    if(start < 0 || start + count > this->sizeD - 1)
    	throw std::out_of_range("start or (start + count) out of range");
    if(copy == true){
    	Darray res1(count);
    	for(int i = 0 ; i < count ; i++)
    		res1.data[i] = this->data[i + start];
    	res1.isProp = true;
    	return res1;
    }
    else {
	// Res.data pointe vers l'élément d'indice start de this->data
    	Darray res2;
    	res2.sizeD = count;
    	res2.data = this->data + start*sizeof(double)/8;
    	res2.isProp = false;
    	return res2;
    }
}
