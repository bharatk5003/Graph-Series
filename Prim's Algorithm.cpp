
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findMinVertex(int* weight, int* visited, int n)
{
	int min =INT_MAX,minVertex;

	for (int i = 0; i < n; i++)
	{
		if (!visited[i] && weight[i] <min){
			minVertex = i;
			min=weight[i];
			
		}

	}
	return minVertex;



}


void Prims(int** edges, int n)
{
	int *parent = new int[n];
	int *weight = new int[n];
	bool *visited = new bool[n];

	for (int i = 0; i < n; i++) {
		visited[i] = false;
		weight[i] = INT_MAX;
		// parent[i] = -1;
	}
	parent[0] = -1;
	weight[0] = 0;

	for (int i = 0; i < n; i++)
	{
		int minVertex = findMinVertex(weight, visited, n);
		visited[minVertex] = true;

		for (int j = 0; j < n; j++)
		{
			if (edges[minVertex][j] != 0 && !visited[j])
			{
				if (edges[minVertex][j] < weight[j])
					weight[j] = edges[minVertex][j];
				parent[j] = minVertex;

			}
		}


	}

	for (int i = 1; i < n; i++)
	{
		if (parent[i] < i)
			cout << parent[i] << " " << i << " " << weight[i] << endl;
		else
			cout << i << " " << parent[i] << " " << weight[i] << endl;

	}


}



int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("../input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("../output.txt", "w", stdout);
#endif

	int n, e;
	cin >> n >> e;

	int** edges = new int*[n];
	for (int i = 0; i < n; i++)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			edges[i][j] = 0;
		}
	}

	for (int i = 0; i < e; i++)
	{
		int f, s, w;
		cin >> f >> s >> w;
		edges[f][s] = w;
	}
	cout << endl;
	prims(edges, n);

	for (int i = 0; i < n; i++)
	{
		delete [] edges[i];
	}

	delete [] edges;


}
