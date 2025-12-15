#pragma once
#include <string>

using namespace std;

class Employee {
    string name;
    int id;
    double salary;

public:
    Employee(string empName, int empId, double empSalary);
    string getName() const;
    int getId() const;
    double getSalary() const;
    void setSalary(double newSalary);
};

bool checkData(const string& name, int id, double salary);
void saveToFile(Employee employees[], int size, const string& filename);