#include "employee.hpp"
#include <fstream>
#include <iostream>

using namespace std;

Employee::Employee(string empName, int empId, double empSalary)
    : name(empName), id(empId), salary(empSalary) {}

string Employee::getName() const {
    return name;
}

int Employee::getId() const {
    return id;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::setSalary(double newSalary) {
    salary = newSalary;
}

bool checkData(const string& name, int id, double salary) {
    if (name.empty()) {
        cout << "нет имени" << endl;
        return false;
    }
    if (id <= 0) {
        cout << "id не подходит" << endl;
        return false;
    }
    if (salary < 0) {
        cout << "зарплата меньше нуля" << endl;
        return false;
    }
    return true;
}

void saveToFile(Employee employees[], int size, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "не открылся файл" << endl;
        return;
    }
    
    for (int i = 0; i < size; ++i) {
        file << employees[i].getId() << " "
             << employees[i].getName() << " "
             << employees[i].getSalary() << endl;
    }
    
    file.close();
    cout << "записано в " << filename << endl;
}