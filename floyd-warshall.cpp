// Program for Floyd Warshall Algorithm
#include<iostream>
using namespace std;
 
// Number of vertices in the graph
#define V 5
 
/* 
 * Define Infinite as a large enough value. This value will be used
 * for vertices not connected to each other 
 */
#define INF 99999
 
// A function to print the solution matrix
void printSolution(int dist[][V]);
 
// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
void floydWarshall (const int (&graph)[V][V], int (&dist)[V][V], int (&pred)[V][V])
{
	int i, j, k;

	/*
	 * Initialize the solution matrix same as input graph matrix. Or 
	 * we can say the initial values of shortest distances are based
	 * on shortest paths considering no intermediate vertex. *
	 */
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++) {
			dist[i][j] = graph[i][j];
			pred[i][j] = INF;
		}

	printf("Iteration[%d] (initial)\n", 0);
	printSolution(dist);

	/*
	 * Add all vertices one by one to the set of intermediate vertices.
	 * ---> Before start of a iteration, we have shortest distances between all
	 * pairs of vertices such that the shortest distances consider only the
	 * vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
	 */
	for (k = 0; k < V; k++)
	{
		// source vertex (0 ~ V-1)
		for (i = 0; i < V; i++)
		{
			// destination vertex (0 ~ V-1)
			for (j = 0; j < V; j++)
			{
				/*
				 * If vertex k is on the shortest path from
				 * i to j, then update the value of dist[i][j]
				 * Also update the predecessor matrix
				 * for path finding
				 */
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					pred[i][j] = k;
				}
			}
		}
		printf("Iteration[%d]\n", k+1);
		printf ("This matrix shows the shortest distances"
				" between every pair of vertices \n");
		printSolution(dist);
	}

	// print the pred matrix
	cout << "Predecessor matrix\n";
	printSolution(pred);
}
 
/* A utility function to print solution */
void printSolution(int dist[][V])
{
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				printf("%3s ", "INF");
			else
				printf ("%3d ", dist[i][j]);
		}
		printf("\n");
	}
}

void printPath(int pred[][V], int src, int dest)
{

	if(pred[src][dest] != INF) {
		printPath(pred, src, pred[src][dest]);
		cout << "v" << pred[src][dest] << " ";
		printPath(pred, pred[src][dest], dest);
	}
}
 
// driver program to test above function
int main()
{
	// initial weight
	const int Weight[V][V] = { 
		{0,    1,  INF,    1,   5},
		{9,    0,    3,    2, INF},
		{INF, INF,   0,    4, INF},
		{INF, INF,   2,    0,   3},
		{3,   INF, INF,  INF,   0} };
	// Dist is the shortest distance matrix, Pred is the predecessor matrix
	int Dist[V][V], Pred[V][V];

	floydWarshall(Weight, Dist, Pred);

	int src, dest;
	while(1) {
		cout << "enter src: ";
		cin >> src;
		cout << "enter dest: ";
		cin >> dest;
		if (src < 0 || src >= V || dest < 0 || dest >= V) {
			cout << "src/dest node id is out of range. try again\n";
			continue;
		}
		if(src != dest) {
			cout << "printPath: " << "v" << src << " ";
			printPath(Pred, src, dest);
			cout << "v" << dest << endl;
		}
		else {
			cout << "Path: v" << src << endl;
		}
	}
	return 0;
}
