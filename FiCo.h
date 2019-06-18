#pragma once
#include "FAMNcl.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;
class FiCo
{
	string filename;
	FAMNcl obj;
	fstream file;

	bool check(fstream & _file);
	
	
public:
	FiCo();
	FiCo(string _filename);
	void fill();
	void clear();

	void read();
	int search(string surname);

	void redact(int position);
};

