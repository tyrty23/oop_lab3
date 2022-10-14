#pragma once
#include <iomanip>
#include <fstream>
#include <iostream>
#include "Fio.h"


using namespace std;

class Worker
{
	friend bool operator==( Worker , Fio );
	friend istream& operator >> (std::istream&, Worker&);
	Fio fio;
	int num_dep;
	double salary;
public:
	static int counter;
	Worker();
	Worker(Fio, int, double);
	static void AddWorker(Worker*);
	static void PrintAll(Worker*);
	static void Save(Worker*);
	static void Load(Worker*);
	static void PrintDep(Worker*);
	static void SortSalary(Worker*);
	static void FindWorker(Worker*);
	static int right_int();
	static double right_double();
	static void line();
	static void PrintOne(Worker*, int);
	static void AddWorker2(Worker*);
};

