#include <iostream>
#include "FiCo.h"
using namespace std;


int main() {
	int   pos;
	FiCo fico("FAMN.txt");
	string  find_surname;
	
		
	while (true) {

		cout << "MENU" << endl
			<< "clear file: 1" << endl
			<< "add to file: 2" << endl
			<< "read file: 3" << endl
			<< "search phone: 4" << endl
			<< "exit: 0" << endl;
		
		switch (_getch() - 48) {
		case 1: fico.clear(); break;
		case 2: fico.fill(); break;
		case 3: fico.read(); break;
		case 4: 
			cout<<endl << "surname: ";
			cin >> find_surname;
			pos = fico.search(find_surname);
			cout << endl << "Are you want redact? (1 - yes/ 2 - no)" << endl;
			if (_getch() - 48 == 1)
				fico.redact(pos);
			break;
		case 0: return 0; break;
		default: cout << "ERROR INPUT! TRY AGAIN!" << endl;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
