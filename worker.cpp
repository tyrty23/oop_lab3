#include "worker.h"

int
Worker::counter = 0;

Worker::Worker()
{
	Fio();
	num_dep = 1;
	salary = 50000;
}

Worker::Worker(Fio fio1, int dep, double sal)
{
	fio = { fio1.GetName(),fio1.GetSurname(),fio1.GetPatronymic() };
	num_dep = dep;
	salary = sal;
}

void Worker::PrintAll(Worker*ar)
{
	line();
	for (int i = 0; i < counter; i++) {
		cout << ar[i] << endl;;
	}
}

void Worker::Save(Worker* ar)
{
	ofstream fout("lab3.txt");
	fout << counter;
	for (int i = 0; i < counter; ++i)
	{
		fout << ar[i].fio.GetName() << " "
			<< ar[i].fio.GetSurname() << " "
			<< ar[i].fio.GetPatronymic() << " "
			<< ar[i].num_dep << " "
			<< ar[i].salary;
	}
	fout.close();
}

void Worker::Load(Worker* ar)
{
	ifstream fin("lab3.txt");
	if (fin.is_open()&& fin.peek() != EOF) {
		string n,s,p;
		fin >> counter;
		for (int i = 0; i < counter; i++) {
			fin
				>> n
				>> s
				>> p
				>> ar[i].num_dep
				>> ar[i].salary;				
			Fio fio1 = { n, s, p };
			ar[i].fio = fio1;
		}
	}
	else {
		ofstream fout("lab3.txt");
		cout << "Введите кол-во новых записей: ";
		int n = right_int();
		for (int i = 0; i < n; i++) {
			AddWorker(ar);
		}
		fout.close();
	}
	fin.close();
}

void Worker::PrintDep(Worker* ar)
{
	bool l = 0;
	int test;
	cout << "Ведите номер отдела: ";
	test = right_int();
	for (int i = 0; i < counter; i++)
		if (test == ar[i].num_dep) {
			l = 1;
		}
	if (l == 0) cout << "Работников введенного департамента в базе нет\n";
	else {
		cout << "Работники данного отдела :\n";
		line();
		for (int i = 0; i < counter; i++) {
			if (test == ar[i].num_dep) {
				cout << ar[i] << endl;;
			}
		}
	}
}

void Worker::SortSalary(Worker* ar)
{
	Worker test;
	for (int i = 0; i < counter; i++)
		for (int a = 0; a < counter; a++)
			if (ar[a].salary < ar[i].salary) {
				test = ar[a];
				ar[a] = ar[i];
				ar[i] = test;
			}
}

void Worker::FindWorker(Worker* ar)
{
	bool l = 0;
	string test;
	Fio test1;
	cout << "Ведите фамилию сотрудника: ";
	cin>>test;
	test1.SetSurname(test);
	for (int i = 0; i < counter; i++)
		if (ar[i] == test1) {
			l = 1;
		}
	if (l == 0) cout << "Работников введенного департамента в базе нет\n";
	else {
		cout << "Работники данного отдела :\n";
		line();
		for (int i = 0; i < counter; i++) {
			if (ar[i] == test1) {
				cout << ar[i] << endl;;
			}
		}
	}
}

int Worker::right_int()
{
	string buff;
	/*cout << "Введите целое число: ";*/
	cin >> buff;
	while (true) {
		if (atoi(buff.c_str()) != false) { return atoi(buff.c_str()); }
		else {
			cout << "Введите целое число: ";
			cin >> buff;
		}
	}
}

double Worker::right_double()
{
	string buff;
	//cout << "Введите число типа double: ";
	cin >> buff;
	while (true) {
		if (atof(buff.c_str()) != false) { return atof(buff.c_str()); }
		else {
			cout << "Введите число типа double: ";
			cin >> buff;
		}
	}
}

void Worker::line()
{
	cout << setw(25) << "ФИО работника"
		<< setw(30) << "Департамент"
		<< setw(15) << "Оклад (&)"<< endl;
}


void Worker::AddWorker(Worker* ar)
{
	cout << "Ввдите нового работника в формате ФИО, отдел, оклад через пробел или enter: \n";
	cin >> ar[counter];
	counter++;
}

bool operator==(Worker w ,  Fio f)
{
	if (w.fio.GetSurname() == f.GetSurname()) {
		return true;
	}
	else {
		return false;
	}
	
}

istream& operator>>(std::istream& in, Worker& w)
{
	in >> w.fio >> w.num_dep >> w.salary;
	return in;
}

ostream& operator<<(std::ostream& out, Worker& w)
{
	out << w.fio
		<< setw(15) << w.num_dep
		<< setw(20) << w.salary << endl;
	return out;
}
