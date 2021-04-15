#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

    void create_edge(vector<int> adj[], int, int);
    bool BFS(vector<int> adj[], int, int, int, int, int);
    void displayShortestNode(vector<int> adj[], int , int , int );


int main()
{
    int v,e, green, yellow;

    cout<<"Enter total number of vertices:";
    cin>>v;
    cout<<"Enter total number of Edges: ";
    cin>>e;
    cout<<"\n";
	vector<int> adj[v];

    for(int i=0; i<e;i++)
    {
        int src, des;
        cout<<"Node for edge "<<i<<" : ";
        cin>> src >>des;
        create_edge(adj,src, des);
    }
    cout<<"Enter starting( Green) vertex :";
    cin>>green;
    cout<<"Enter target ( yellow ) vertex :";
    cin>>yellow;

	displayShortestNode(adj, green, yellow, v);
	getch();
	return 0;
}



void create_edge(vector<int> adj[], int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}



bool BFS(vector<int> adj[], int src, int dest, int v,
		int pred[], int dist[])
{
	list<int> queue;

	bool visited[v];

	for (int i = 0; i < v; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
		pred[i] = -1;
	}

	visited[src] = true;
	dist[src] = 0;
	queue.push_back(src);

	while (!queue.empty()) {
		int u = queue.front();
		queue.pop_front();
		for (int i = 0; i < adj[u].size(); i++) {
			if (visited[adj[u][i]] == false) {
				visited[adj[u][i]] = true;
				dist[adj[u][i]] = dist[u] + 1;
				pred[adj[u][i]] = u;
				queue.push_back(adj[u][i]);

				if (adj[u][i] == dest)
					return true;
			}
		}
	}

	return false;
}

void displayShortestNode(vector<int> adj[], int s,
						int dest, int v)
{

	int pred[v], dist[v];

	if (BFS(adj, s, dest, v, pred, dist) == false) {
		cout << "No edges are connected";
		return;
	}

	vector<int> path;
	int c = dest;
	path.push_back(c);
	while (pred[c] != -1) {
		path.push_back(pred[c]);
		c = pred[c];
	}

	cout << "\nGreen to Yellow Shortest path length is : "
		<< dist[dest];

	cout << "\n\nGreen to Yellow Shortest Path : ";
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << "  ";
}

