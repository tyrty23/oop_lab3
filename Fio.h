#pragma once
#include <string>
#include <iostream>


using namespace std;

class Fio
{
	friend istream& operator >> (std::istream& in, Fio& f);
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
	bool operator ==(const Fio other);
	

};

