#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

//Merge Sort Algorithm
void merge(int arr[], int l, int mid, int r,int aux[]) {
	for (int i = l; i <= r; i++)
		aux[i] = arr[i];

	int i = l;
	int j = mid+1;
	int k = l;

	while (k <= r) {
		if (i > mid) {
			arr[k] = aux[j];
			j++;
		}
		else if (j > r) {
			arr[k] = aux[i];
			i++;
		}else if (aux[i] <= aux[j]) {
			arr[k] = aux[i];
			i++;
		}
		else if (aux[i] > aux[j]) {
			arr[k] = aux[j];
			j++;
		}
		k++;
	}
}
void __mergeSort(int arr[], int l, int r, int aux[]) {
	
	if (l >= r)
		return;

	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid,aux);
	__mergeSort(arr, mid + 1, r,aux);

	merge(arr, l, mid, r,aux);
}

void mergeSort(int arr[], int n) {
	int* aux = new int[n];
	__mergeSort(arr, 0, n - 1,aux);

	delete[] aux;
}

int main() {

	int testInt[] = { 6,3,5,1,9,4,2 };
	int n = sizeof(testInt) / sizeof(int);
	for (int i = 0;i < n; i++) {
		cout << testInt[i] << " ";
	}
	cout << endl;
	mergeSort(testInt, n);
	for (int i = 0;i < sizeof(testInt) / sizeof(int); i++) {
		cout << testInt[i] << " ";
	}
}