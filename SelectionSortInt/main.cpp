#include <iostream>
using namespace std;
void printArray(int a[] , int arraySize );
void selectionSort(int a[] , int arraySize);
void swapInt(int &x , int &y) ;
int main()
{
    int arraySize = 6;
    int a[arraySize] = {1,7,2,8,9,22} ;
    cout << "Before Sort: " <<endl;
    printArray(a, arraySize);

    selectionSort(a , arraySize);

    cout << "After Sort: " <<endl;
    printArray(a, arraySize);
    return 0;
}
void selectionSort(int a[], int arraySize) {
    int minIndex ;
    for (int i= 0 ; i <arraySize-1 ; i++){
        minIndex = i ;
        for(int k = i+1 ; k < arraySize ; k++){
            if(a[k] < a[minIndex]){
                minIndex=k;
            }
        }
         swapInt(a[i] , a[minIndex]);
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
