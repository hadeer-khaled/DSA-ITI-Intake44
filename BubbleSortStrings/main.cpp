#include <iostream>
#include <string>
using namespace std;

void printArray(string a[], int arraySize);
void bubbleSort(string a[], int arraySize);
void swapString(string &x, string &y);

int main() {
    int arraySize = 4;
    string a[arraySize] = {"ali" , "Alaa" , "Ali" , "alaa"};
    cout << "Before Sort: ";
    printArray(a, arraySize);

    bubbleSort(a, arraySize);

    cout << "After Sort: ";
    printArray(a, arraySize);
    return 0;
}

void bubbleSort(string a[], int arraySize) {
    for (int i = 0; i < arraySize - 1; i++) {
        for (int k = 0; k < arraySize - i - 1; k++) {
            if (a[k] > a[k + 1]) {
                swapString(a[k], a[k + 1]);
            }
        }
    }
}

void swapString(string &x, string &y) {
    string temp = x;
    x = y;
    y = temp;
}

void printArray(string a[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout <<a[i] << " , ";
    }
    cout << endl;
}
