#include <iostream>
using namespace std;

void sentinelSearch(int arr[], int Size, int key)
{
	int endElem = arr[Size - 1];

	arr[Size - 1] = key;
	int i = 0;

	while (arr[i] != key){
		i++;
	}

	arr[Size - 1] = endElem;

	if ((i < Size - 1) || (arr[Size - 1] == key))
		cout <<"Element: "<<key << " exist at index " << i;
	else
		cout << "Element doesn't exist";
}

int main()
{
	int arr[] = { -3, 7 , 10 , 26 , 99 };
	int Size = sizeof(arr) / sizeof(arr[0]);
	int key = 10;

	sentinelSearch(arr, Size, key);

	return 0;
}
