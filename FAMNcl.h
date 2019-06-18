#pragma once
#include <iostream>
#include <string>
using namespace std;
#define mxp 9 //phon lenght


class FAMNcl
{
	int ph_number[mxp];
	string surname;

	void copy(const int * from, int * in);
	void fill_phon();
public:
	FAMNcl();
	FAMNcl(int * phone, string sname);
	FAMNcl(const FAMNcl & obj);

	int & get_phone();
	string get_surname();
	
	void fill();

};

