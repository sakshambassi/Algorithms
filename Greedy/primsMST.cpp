#include <bits/stdc++.h>

#define n 5

using namespace std;

int minKey(bool mstSet[],int key[])
{
	int min = INT_MAX, min_index;

	for (int i = 0; i < n; ++i)
	{
		if (mstSet[i] == false && key[i]<min)
		{
			min = key[i];
			min_index = i;
		}
	}
	return min_index;
}

void printMST(int parent[], int graph[n][n])
{
	cout<<"EDGE  WEIGHT\n";
	for (int i = 1; i < n; ++i)
	{
		cout<<parent[i]<<" - "<<i<<"  "<<graph[i][parent[i]]<<"\n";
	}
}

void primMST(int graph[n][n])
{
	int parent[n];
	int key[n];
	bool mstSet[n];

	for (int i = 1; i < n; ++i)
	{
		key[i] = INT_MAX;
		mstSet[i] = false;
	}

	key[0] = 0;
	parent[0] = -1;
	mstSet[0] = false;

	for (int i = 0; i < n-1; ++i)
	{
		int u = minKey(mstSet, key);

		mstSet[u] = true;

		for (int v = 0; v < n; ++v)
		{
			if (graph[u][v] && mstSet[v]==false && graph[u][v] < key[v])
			{
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}
	printMST(parent, graph);
}

int main(int argc, char const *argn[])
{
	int graph[n][n] = {{0, 2, 0, 6, 0},
				{2, 0, 3, 8, 5},
				{0, 3, 0, 0, 7},
				{6, 8, 0, 0, 9},
				{0, 5, 7, 9, 0},
				};

	// Print the solution
	primMST(graph);
	return 0;
}