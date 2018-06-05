#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int n)
{
	int key,j;
	for (int i = 1; i < n; ++i)
	{
		key = arr[i];
		j = i-1;
		while(arr[j]>key && j>=0)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}

void printSolution(int arr[], int n)
{
	int i;
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
}

int main()
{
	int arr[] = {12, 11, 13, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	insertionSort(arr, n);
	printSolution(arr, n);
	
	return 0;
}