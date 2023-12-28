#include <iostream>
#include<algorithm>
using namespace std ;
void swapInt(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}
int Partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swapInt(arr[i], arr[j]);
        }
    }

   swapInt(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex =  Partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);

        quickSort(arr, pivotIndex + 1, high);
    }
}
void printArray(int arr[], int Size) {
    for (int i = 0; i < Size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 7, 11, 8, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sort array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "After Sort array: ";
    printArray(arr, n);

    return 0;
}
