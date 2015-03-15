#include "Point.h"
#include "Triangle.h"
#include "Maillage.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cassert>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	Maillage<double	, std::vector> m(1,1,Point<double>(0,0));
	cout << m;
}
