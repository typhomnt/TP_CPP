#include "Dvector.h"
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

int main() {
	Dvector v1(50000000, 4.5);
	Dvector v2;
	clock_t temps = clock();
	v2 = v1;
	temps = clock()-temps;
	cout << temps/(double)CLOCKS_PER_SEC << endl;

	Dvector v3(v1.size());
	clock_t temps2 = clock();
	for(int i = 0; i < v1.size() ; i++){
			v3(i) = v1(i);
	}
	temps2 = clock() - temps2;
	cout << temps2/(double)CLOCKS_PER_SEC << endl;
	cout << "Rapport = " << (double)temps2/(double)temps << endl;
}
