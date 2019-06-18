#include "FiCo.h"

bool FiCo::check(fstream & _file)
{
	if (_file)
		return true;
	else
		return false;
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
	if (check(file)) {
		cout << " to extit: esc" << endl;
		while(true){
			if (_getch() == 27)
				break;
			obj.fill();
			file << obj.get_surname() << ' ';
			for(int i = 0 ; i < mxp; i++)
				file << obj.get_phone()+i;
			file << endl;
		}
	}
	file.close();
}

void FiCo::clear()
{
	file.open(filename, ios::out|ios::trunc);
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
	int seek = 0;
	file.open(filename, ios::in);
	if (check(file)) {
		string word;
		
		while (file >> word) {
			if (_surname == word) {
				seek = file.tellg();
				seek -= word.length();
				cout << word << ' ';
				file >> word;
				cout << word<< endl;
			}
		}
	}
	file.close();
	return seek;
}

void FiCo::redact(int position)
{
	fstream nfile("new.txt", ios::out|ios::trunc);
	obj.fill();
	string buf;
	file.open(filename, ios::out|ios::in);
	if (check(file)) {
				
	while (file.tellg() < position) {
		file >> buf;
		nfile << buf<< ' ';
		file >> buf;
		nfile << buf << endl;
		}
		
		nfile.seekp(position);
		nfile << obj.get_surname() << ' ';
		for (int i = 0; i < mxp; i++)
			nfile << *(&obj.get_phone() + i);
		nfile << endl;

		while (file >> buf) {
			nfile << buf << ' ';
			file >> buf;
			nfile << buf << endl;
		}
		
		file.close();
		nfile.close();
		remove(filename.c_str());
		rename("new.txt", filename.c_str());
	}
	
}
