#include <bits/stdc++.h>

using namespace std;
////////////////////////////////////////////
struct minmax
{
	int min;
	int max;
};
////////////////////////////////////////////
struct minmax getminmax(int low, int high, int a[])
{
	int mid;
	struct minmax ret,left,right;

	if (low == high)
	{
		ret.max = a[low];
		ret.min = a[low];
		return ret;
	}
	if (high == low + 1)
	{
		if (a[low] < a[high])
		{
			ret.max = a[high];
			ret.min = a[low];
		}
		else
		{
			ret.max = a[low];
			ret.min = a[high];
		}
		return ret;
	}
	mid = (low+high)/2;
	left = getminmax(low, mid, a);
	right = getminmax(mid+1, high, a);
	ret.min = (left.min < right.min) ? left.min : right.min;
	ret.max = (left.max > right.max) ? left.max : right.max;
	
	return ret;
}
///////////////////////////////////////////
int main()
{
	int i, num;
	struct minmax result;
	cout<<"\nEnter the total number of numbers : ";
	cin>>num;
	int a[num];
	cout<<"Enter the numbers : \n";
	for (i=0;i<num;i++)
		cin>>a[i];

	result = getminmax(0, num-1, a);
	cout<<"Minimum element in an array : "<<result.min<<"\n";
	cout<<"Maximum element in an array : "<<result.max<<"\n";
	return 0;
}