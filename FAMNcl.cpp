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
FAMNcl::FAMNcl()
{
	ph_number[0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
	surname = "undefined";
}

FAMNcl::FAMNcl(int * phone, string sname)
{
	copy(phone, ph_number);
	surname = sname;
}

FAMNcl::FAMNcl(const FAMNcl& obj)
{
	copy(obj.ph_number, ph_number);
	surname = obj.surname;
}

int & FAMNcl::get_phone()
{
	return * ph_number;
}

string FAMNcl::get_surname()
{
	return surname;
}

void FAMNcl::fill()
{
	
	int phone[mxp];
	cout << "Phone(" << mxp << " numbers): ";
	for (int i = 0; i < mxp; i++)
		cin >> phone[i];
	cout << "surname: ";
	cin >> surname;
	
}


