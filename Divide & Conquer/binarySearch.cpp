#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int start, int end, int searchKey)
{
	int mid = (start + end)/2;
	if (arr[mid] == searchKey)
		return mid;
	return (arr[mid] > searchKey) ? binarySearch(arr, start, mid, searchKey) : binarySearch(arr, mid+1, start, searchKey);

	return -1;
}

int main(void)
{
   int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int searchKey = 10;
   int result = binarySearch(arr, 0, n-1, searchKey);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d\n",
                                                   result);
   return 0;
}