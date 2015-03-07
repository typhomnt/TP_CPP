#include "Dmatrix.h"
#include <cassert>
using namespace std;

int main(){
	Dmatrix v;
	assert(v.size() == 0);
	assert(v.getData() == NULL);
	assert(v.isOwner() == true);
	assert(v.lines() == 0);
	assert(v.columns() == 0);
	cout << "TEST DU CONSTRUCTEUR PAR DEFAUT DE DMATRIX : OK" << endl;
}
