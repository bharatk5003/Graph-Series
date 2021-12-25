#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Edge
{
public:
	int source;
	int destination;
	int weight;
};
int findParent(int source, int* parent)
{
	if (parent[source] == source)
		return source;

	return findParent(parent[source], parent);
}


bool compare(Edge e1, Edge e2)
{
	return e1.weight < e2.weight;
}


void Kruskals(Edge* input, int V, int E)
{
	//cout << "My Name is Bharat" << endl;
	sort(input, input + E, compare);

	Edge output[V - 1];

	int *parent = new int[V];
	for (int i = 0; i < V; ++i)
	{
		parent[i] = i;

	}


	int count = 0;
	int i = 0;

	while (count != V - 1)
	{
		Edge currentEdge = input[i];

		int sourceParent = findParent(currentEdge.source, parent);
		int destParent = findParent(currentEdge.destination, parent);

		if (sourceParent != destParent)
		{
			output[count] = currentEdge;
			count++;
			parent[sourceParent] = destParent;

		}
		i++;


	}
//	cout << "Hi There" << endl;

	for (int i = 0; i < V - 1; i++)
	{

		if (output[i].source < output[i].destination)
		{
			cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
		}
		else
		{
			cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
		}

	}
	//delete [] output;

}



int main()
{
	//cout << "Hello Bharat" << endl;
	int V, E;
	cin >> V >> E;
	Edge input[E];
	//Edge output[V - 1];


	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		input[i].source = u;
		input[i].destination = v;
		input[i].weight = w;
	}


	Kruskals(input, V, E);
	/*Input for this program
		6 11
		0 1 2
		1 3 1
		0 2 4
		2 4 9
		4 5 5
		3 5 7
		4 3 11
		2 5 10
		0 3 3
		2 1 8
		2 3 6
	*/


	/* Answer
	1 3 1
	0 1 2
	0 2 4
	4 5 5
	3 5 7
	*/



}

