#include<bits/stdc++.h>

using namespace std;

int LIS(int arr[], int size)
{
	int lis[size], max = 0;
	int i, j;
	for (int i = 0; i < size; ++i)
		lis[i] = 1;
	
	for ( i = 1; i < size; ++i)
		for ( j = 0; j < i; ++j)
			if (arr[j] < arr[i] && lis[j]+1 > lis[i])
				lis[i] = lis[j]+1;

	for (int i = 0; i < size; ++i)
		if (max < lis[i])
			max = lis[i];
	return max;

}
int main()
{
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60 };
	int size = sizeof(arr)/sizeof(arr[0]);
	int result = LIS(arr,size);
	cout<<"LIS is :"<<result;
	return 0;
}