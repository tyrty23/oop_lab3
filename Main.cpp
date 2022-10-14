#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include "worker.h"
#include "Fio.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "Russian");
    class Worker* ar = new Worker[10];

    Worker::Load(ar);

    while (true) {
        cout << "==============================================================================\n";
        cout << "\t ----------------------------------------------------------\n";
        cout << "\t |            ��������, ��� �� ������ �������              |\n";
        cout << "\t ----------------------------------------------------------\n";
        cout << "\t   1-�������� ���������\n\t   2-����������� �������\n\t   3-����� ���������� ������������\n"
            << "\t   4-����������� �� ���������� ������\n\t   5-����� ���������� �� �������\n"
            << "\t   6-�������� ��������� � ������� �������������� ���������\n\t   7-��������� ������\n";
        cout << "==============================================================================\n";
        int t;
        t = Worker::right_int();
        if (t == 1) {
            system("cls");
            Worker::AddWorker(ar);
        }
        if (t == 2) {
            system("cls");
            Worker::PrintAll(ar);
        }
        if (t == 3) {
            system("cls");
            Worker::PrintDep(ar);
        }
        if (t == 4) {
            system("cls");
            Worker::SortSalary(ar);
        }
        if (t == 5) {
            system("cls");
            Worker::FindWorker(ar);
        }
        if (t == 6) {
            system("cls");
            Worker::AddWorker2(ar);
        }
        if (t == 7) {
            system("cls");
            Worker::Save(ar);
            break;
        }
        if (t != 1 && t != 2 && t != 3 && t != 4 && t != 5 && t != 6 ) {
            cout << "�������� �������" << endl;
        }
    }
}