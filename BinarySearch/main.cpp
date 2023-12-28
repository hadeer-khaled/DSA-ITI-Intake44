#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key)
{
	while (left <= right) {
		int mid = (left + right) / 2;

		if (arr[mid] == key)
			return mid;

		if (arr[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1;
}
int main(void)
{
    int Size = 5;
	int arr[] = { -3, 7 , 10 , 26 , 99 };
	bubbleSort(arr,Size);
	int key = 10;
	int result = binarySearch(arr, 0, Size - 1, key);
	if (result ==  -1){
        cout << "Element doesn't exist in array";
	}
	else{
         cout << "Element: " << key << " exist at index:  " << result;
	}
	return 0;
}
