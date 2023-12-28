#include <iostream>
using namespace std;
void printArray(int a[] , int arraySize );
void bubbleSort(int a[] , int arraySize);
void swapInt(int &x , int &y) ;
int main()
{
    int arraySize = 6;
    int a[arraySize] = {1,7,2,8,9,22} ;
    cout << "Before Sort: ";
    printArray(a, arraySize);

    bubbleSort(a , arraySize);

    cout << "After Sort: ";
    printArray(a, arraySize);
    return 0;
}
void bubbleSort(int a[], int arraySize) {
    for (int i = 0; i < arraySize - 1; i++) {
        for (int k = 0; k < arraySize - i - 1; k++) {
            if (a[k] > a[k + 1]) {
                swapInt(a[k], a[k + 1]);
            }
        }
    }
}
void swapInt(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}
void printArray(int a[] ,int arraySize ){
    for(int i = 0 ; i<arraySize-1 ; i++){
        cout << a[i] << endl;
    }
}
