#include <bits/stdc++.h>

using namespace std;

struct Job
{
	int id;
	int deadLine;
	int profit;
};

bool comparision(Job a, Job b)
{
	return (a.profit > b.profit);	//decreasing order
}
void printJobSequencing(Job arr[], int n)
{
	sort(arr, arr+n, comparision);
	int result[n];
	for(int i=0; i<n; i++)
	{
		result[i]=-1;
	}
	for(int i=0; i<n; i++)
	{
		int j=arr[i].deadLine-1;
		if(result[(arr[i].deadLine)-1]==-1)
		{
			result[(arr[i].deadLine)-1] = arr[i].id;
		}
		else
		{
			if(j==0)
			{
				cout<<"can't consider\n";
			}
			while(j>=0)
			{
				j=j-1;
				if(result[j]==-1)
				{
					result[j]=arr[i].id;
				}
			}
		}
	}
	for(int i=0; i<n; i++)
	{
		cout<<"i: "<<result[i];
	}
}

int main()
{
	Job arr[] = { {0, 2, 100}, {1, 1, 19}, {2, 2, 27},{3, 1, 25}, {4, 3, 15}};
	int n = sizeof(arr)/sizeof(arr[0]);
	printJobSequencing(arr, n);
}