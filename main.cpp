#include "employee.hpp"
#include <iostream>

using namespace std;

int main() {
    Employee employees[5] = {
        Employee("", 0, 0),
        Employee("", 0, 0),
        Employee("", 0, 0),
        Employee("", 0, 0),
        Employee("", 0, 0)
    };
    
    int count = 0;
    while (count < 3) {
        string name;
        int id;
        double salary;
        
        cout << "сотрудник " << count + 1 << endl;
        cout << "имя: ";
        getline(cin, name);
        cout << "id: ";
        cin >> id;
        cout << "зарплата: ";
        cin >> salary;
        cin.ignore();
        
        if (checkData(name, id, salary)) {
            employees[count] = Employee(name, id, salary);
            count++;
        } else {
            cout << "снова" << endl;
        }
    }
    
    cout << endl << "список:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "id: " << employees[i].getId()
             << ", имя: " << employees[i].getName()
             << ", зарплата: " << employees[i].getSalary() << endl;
    }
    
    saveToFile(employees, 3, "employees.txt");
    
    return 0;
}