#include <bits/stdc++.h>

using namespace std;

void printMaxActivities(int s[],int f[], int n)
{
	int LastTime=f[0];
	for(int i=0; i<n; i++)
	{
		if(i==0)
		{
			cout<<i<<" ";
		}
		else
		{
			if(s[i]>=LastTime)
			{
				cout<<i<<" ";
				LastTime=f[i];
			}
		}
	}
}

int main()
{
    int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n);
    return 0;
}
