#include "FAMNcl.h"
void FAMNcl::copy(const int* from, int* in)
{
	try {
		for (int i = 0; i < mxp; i++) {
			in[i] = from[i];
		}
	}
	catch (...) {
		cout << "some error" << endl;
	}
}
void FAMNcl::fill_phon()
{
	string tnumber;

	cout << "Phone(" << mxp << " numbers): ";
	cin >> tnumber;
	int k = 0;
	if (tnumber.length() == mxp)
		for (int i = 0; i < tnumber.length(); i++)
			if (isdigit(tnumber[i]))
				try {
				ph_number[i] = tnumber[i] - 48;
				k++;
			}
	catch (exception& e) {
		cout << e.what() << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		fill_phon();
	}

	if (k != mxp) {
		cout << "Uncorrect number" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		fill_phon();
	}

}
FAMNcl::FAMNcl()
{
	ph_number[0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
	surname = "undefined";
}

FAMNcl::FAMNcl(int * phone, string sname)
{
		surname = sname;
}

FAMNcl::FAMNcl(const FAMNcl& obj)
{
	
	surname = obj.surname;
}

int & FAMNcl::get_phone()
{
	return  * ph_number;
}

string FAMNcl::get_surname()
{
	return surname;
}

void FAMNcl::fill()
{
	

	fill_phon();

	cout << "surname: ";
	cin >> surname;
}


