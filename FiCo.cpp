#include "FiCo.h"

bool FiCo::check(fstream & _file)
{
	if (_file)
		return true;
	else
		return false;
}

void FiCo::write(FAMNcl obj)
{
	file  << obj.get_surname() << ' ' << obj.get_phone() <<endl;
}

FiCo::FiCo()
{
	filename = "undefinedFN";
}

FiCo::FiCo(string _filename)
{
	file.open(_filename);
	if (file) {
		filename = _filename;
	}
	else {
		cout << "error file opening" << endl;
	}
	file.close();
}

void FiCo::fill()
{
	file.open(filename, ios::out | ios::app);
	obj.fill();
	if (check(file)) {
		write(obj);
	}
	file.close();
}

void FiCo::read()
{
	file.open(filename, ios::in);
	if (check(file)) {
		string word;
		while (file >> word) {
			cout << word << ' ';
			file >> word;
			cout << word << endl;
		}
	}
	file.close();
}

int FiCo::search(string _surname)
{
	file.open(filename, ios::in);
	if (check(file)) {
		string word;
		while (file >> word) {
			if (_surname == word) {
				cout << word << ' ';
				file >> word;
				cout << word<< endl;
			}
		}
	}
	file.close();
}
