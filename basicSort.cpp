#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

void selectSort(int arr[], int n) {
	for (int i = 0; i < n-1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n;i++) {
		for (int j = n - 1; j > i;j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
		}
	}
}

void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int temp = arr[i];
		int j;
		for (j = i; j > 0 && arr[j - 1] > temp; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}


/*int main()
{
	int a1[] = { 1,2,4,5,3 };
	int a2[] = { 3 };

	insertionSort(a1, 5);

	for (int i = 0; i < 5;i++) {
		cout << a1[i] << " ";
	}
	system("pause");
	return 0;
}*/