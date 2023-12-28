#include <iostream>
#include <vector>
using namespace std;

class Employee {
private:
    int id;
    int salary;

public:

    Employee(int empId  , int salary = 0) {
        this->id = empId ;
        this->salary = salary;
    }
    int getId() {
        return id;
    }
        int getSalary() {
        return salary;
    }
};

void empBubbleSort(vector<Employee> &employeesVector, int empNumbers) {
    for (int i = 0; i < empNumbers - 1; i++) {
        for (int k = 0; k < empNumbers - i - 1; k++) {
            if (employeesVector[k].getId() > employeesVector[k + 1].getId()) {
                swap(employeesVector[k], employeesVector[k + 1]);
            }
        }
    }
}

void printArray(vector<Employee> &employeesVector, int empNumbers) {
    for (int i = 0; i < empNumbers; i++) {
        cout << "# ------------------ Employee No. [ " << i << " ] -----------------#" << endl;
        cout << "ID: " << employeesVector[i].getId() << endl;
        cout << "Salary: " << employeesVector[i].getSalary()  << endl;
    }
}

int main() {
    vector<Employee> employeesVector;
    employeesVector.push_back(Employee(6 , 2000));
    employeesVector.push_back(Employee(16, 2400));
    employeesVector.push_back(Employee(10, 2001));
    employeesVector.push_back(Employee(61 , 15000));

    int empNumbers = employeesVector.size();

    empBubbleSort(employeesVector, empNumbers);
    printArray(employeesVector, empNumbers);

    return 0;
}
