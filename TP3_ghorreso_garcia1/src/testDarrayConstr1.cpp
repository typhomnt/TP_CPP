#include "Darray.h"
#include <cassert>
using namespace std;

int main(){
	Darray v;
	assert(v.size() == 0);
	assert(v.getData() == NULL);
	assert(v.isOwner() == true);
	cout << "TEST DU CONSTRUCTEUR PAR DEFAUT DE DARRAY: OK" << endl;
}