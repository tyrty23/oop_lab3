#include "Fio.h"

Fio::Fio()
{
	name = "Иван";
	surname = "Иванов";
	patronymic = "Иванович";
}

Fio::Fio(string n, string s, string p)
{
	name = n;
	surname = s;
	patronymic = p;
}

string Fio::GetName()
{
	return name;
}

string Fio::GetSurname()
{
	return /*this->*/surname;
}

string Fio::GetPatronymic()
{
	return patronymic;
}

void Fio::SetName(string n)
{
	name = n;
}

void Fio::SetSurname(string s)
{
	surname = s;
}

void Fio::SetPatronymic(string p)
{
	patronymic = p;
}


istream& operator>>(std::istream& in, Fio& f)
{
	in >> f.name >> f.surname >> f.patronymic;
	return in;
}
