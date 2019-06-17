#pragma once
#include "FAMNcl.h"
#include <fstream>
using namespace std;
class FiCo
{
	string filename;
	FAMNcl obj;
	fstream file;

	bool check(fstream & _file);
	void write(FAMNcl obj);
	
public:
	FiCo();
	FiCo(string _filename);
	void fill();

	void read();
	int search(string surname);
};

