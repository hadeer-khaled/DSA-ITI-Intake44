#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
private:
    int id;
    int salary;
    string name;

public:
    Employee(int empId, int salary = 0, string name = " ") {
        this->id = empId;
        this->salary = salary;
        this->name = name;
    }
    int getId() {
        return id;
    }
    int getSalary() {
        return salary;
    }
    string getName() {
        return name;
    }
};

// Linear search by Name
int linearSearchByName(Employee arr[], int Size, string name) {
    for (int i = 0; i < Size; ++i) {
        if (arr[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

// Linear search by Id
int linearSearchById(Employee arr[], int Size, int id) {
    for (int i = 0; i < Size; ++i) {
        if (arr[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

// Linear search by Salary
vector<int> linearSearchBySalary(Employee arr[], int Size, int salary) {
    vector<int> matchingEmployeesIndex;

    for (int i = 0; i < Size; ++i) {
        if (arr[i].getSalary() == salary) {
            matchingEmployeesIndex.push_back(i);
        }
    }

    return matchingEmployeesIndex;
}

int main() {
    int Size = 5;
    Employee employees[5] = {
        Employee(1, 50000, "ali"),
        Employee(2, 60000, "hader"),
        Employee(3, 70000, "rahma"),
        Employee(4, 70000, "omar"),
        Employee(5, 70000, "hala")
    };

    string keyName = "rahma";
    int searchResultName = linearSearchByName(employees, Size, keyName);
    if (searchResultName == -1) {
        cout << "The employee does not exist";
    } else {
        cout << "The employee with name [ " << keyName << " ] exists at position [ " << searchResultName + 1 << " ]" << endl;
    }

    int keyId = 1;
    int searchResultkeyId = linearSearchById(employees, Size, keyId);
    if (searchResultkeyId == -1) {
        cout << "The employee does not exist";
    } else {
        cout << "The employee with id  [ " << keyId << " ] exists at position [ " << searchResultkeyId + 1 << " ]" << endl;
    }

    int keySalary = 70000;
    vector<int> searchResultkeySalary = linearSearchBySalary(employees, Size, keySalary);
    if (searchResultkeySalary.size() == 0) {
        cout << "The employee does not exist";
    } else {
        for (int i = 0; i < searchResultkeySalary.size(); ++i) {
            cout << "The employee with salary  [ " << keySalary << " ] exists at position [ " << searchResultkeySalary[i] + 1 << " ]" << endl;
        }
    }
    return 0;
}
