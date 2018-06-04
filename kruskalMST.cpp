#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int src, dest, weight;
};

struct Graph
{
	int V, E;

	struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;

	graph -> V = V;
	graph -> E = E;
	graph -> edge = new Edge[E];

	return graph;
}

struct Subset
{
	int parent;
	int rank;
};

int find(struct Subset subset[], int i)
{
	if(subset[i].parent != i)
		subset[i].parent = find(subset, subset[i].parent);

	return subset[i].parent;
}

void Union(struct Subset subset[], int x, int y)
{
	int xroot = find(subset, x);
	int yroot = find(subset, y);

	if (subset[xroot].rank > subset[yroot].rank)
	{
		subset[yroot].parent = xroot;
	}
	else if (subset[xroot].rank < subset[yroot].rank)
	{
		subset[xroot].parent = yroot;
	}

	else
	{
		subset[yroot].parent = xroot;
		subset[xroot].rank++;
	}
}

bool comparision(struct Edge a, struct Edge b)
{
	return (a.weight < b.weight);
}

void kruskalMST(struct Graph* graph)
{
	int i=0,e=0;
	int V = graph -> V;
	struct Edge result[V];

	sort(graph->edge, graph->edge+graph->E, comparision);

	struct Subset* subset = new Subset[V];

	for (int i = 0; i < V; ++i)
	{
		subset[i].parent = i;
		subset[i].rank = 0;
	}

	while (e < V-1)
	{
		struct Edge next = graph->edge[i++];

		int x = find(subset, next.src);
		int y = find(subset, next.dest);

		if ( x != y)
		{
			result[e++] = next;
			Union(subset, x, y);
		}
	}
	cout<<"Following are the edges in the constructed MST\n";
	for (i = 0; i < e; ++i)
		cout<<result[i].src<<" -- "<<result[i].dest<<" == "<<result[i].weight<<"\n";
	return;
}

int main()
{
	int V = 4;
	int E = 5;
	struct Graph* graph = createGraph(V,E);

	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 10;

	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 6;

	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 5;

	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 15;

	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 4;

	kruskalMST(graph);

	return 0;
}