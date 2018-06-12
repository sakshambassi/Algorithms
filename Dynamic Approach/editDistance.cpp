#include<bits/stdc++.h>

using namespace std;

int min(int x, int y, int z)
{
	return min(min(x,y),z);
}

int editDistance(string s, string r, int m, int n)
{
	int result[m+1][n+1];

	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if ( i == 0)
			{
				result[i][j] = j;			
			}

			else if ( j ==0 )
			{
				result[i][j] = i;
			}
			else if (s[i-1] == r[j-1])
			{
				result[i][j] = result[i-1][j-1];
			}
			else
				result[i][j] = 1 + min(result[i-1][j-1] , result[i][j-1], result[i-1][j]);
		}
	}

	return result[m][n];
}

int main(int argc, char const *argv[])
{
	string s = "sunday";
	string r = "saturday";

	cout<<editDistance(s, r, s.length(), r.length());
	return 0;
}