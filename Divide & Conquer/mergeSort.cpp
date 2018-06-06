#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int i,j;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (int i = 0; i < n1; ++i)
		L[i] = arr[l+i];
	for (int i = 0; i < n2; ++i)
		R[i] = arr[m+1+i];
	i = j = 0;
	while(i < n1 && j < n2)
	{
		if (L[i] < R[j])
		{
			arr[l] = L[i];
			i++; 
		}
		else
		{
			arr[l] = R[j];
			j++;
		}
		l++;
	}

	while(i < n1)
	{
		arr[l] = L[i];
		i++;
		l++;
	}
	while(j < n2)
	{
		arr[l] = R[j];
		j++;
		l++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if ( l < r)
	{
		int m = l + (r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<A[i]<<" ";
    cout<<"\n";
}

int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}