#ifndef MAILLAGEH
#define MAILLAGEH
#include <iostream>
#include <istream>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Triangle.h"

template <typename T>
template <typename C>
class Maillage {
 private:
 
    C<T> mesh;

 public:
    Maillage(int m, int n, const Point<T>& origine);
    const C<T>::iterator& beginiter();
    const C<T>::iterator& enditer();

};


#include "Maillage.tpp"
#endif
