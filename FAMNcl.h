#pragma once

#include <iostream>
#include <string>


using namespace std;
#define mxp 9


class FAMNcl
{
	int ph_number[mxp];
	string surname;

	void copy(const int * from, int * in);
public:
	FAMNcl();
	FAMNcl(int * phone, string sname);
	FAMNcl(const FAMNcl & obj);

	int & get_phone();
	string get_surname();
	
	//зчитувати з клави
	void fill() {
		int phone[mxp];
		cout << "Phone("<<mxp<<" numbers): ";
		for (int i = 0; i < mxp; i++)
			cin >> phone[i];
		cout << "surname: ";
		cin >> surname;
	}

};

