#include <iostream>
#include "FiCo.h"
using namespace std;


int main() {
	string find_surname;
	FiCo fico("FAMN.txt");
	fico.fill();
	fico.read();
	cin >> find_surname;
	cout<<endl<<fico.search("qwerty");
	if(fico.search("qwerty"))
		fico.redact(fico.search("qwerty"));
	return 0;
}
