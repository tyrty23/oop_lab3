#pragma once
#include <string>
#include <iostream>
#include <iomanip>


using namespace std;

class Fio
{
	friend istream& operator >> (std::istream& in, Fio& f);
	friend ostream& operator << (std::ostream&, Fio&);

	string name;
	string surname;
	string patronymic;
public:
	Fio();
	Fio(string, string, string);
	string GetName();
	string GetSurname();
	string GetPatronymic();
	void SetName(string);
	void SetSurname(string);
	void SetPatronymic(string);
	

};

