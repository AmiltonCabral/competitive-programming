// C++ Program to find Dijkstra's shortest path using
// priority_queue in STL
#include <bits/stdc++.h>
using namespace std;
#define INF LONG_LONG_MAX

// iPair ==> long longeger Pair
typedef pair<long long, long long> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph {
    long long V;  // No. of vertices

    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list<pair<long long, long long> >* adj;

   public:
    Graph(long long V);  // Constructor

    // function to add an edge to graph
    void addEdge(long long u, long long v, long long w);

    // prlong longs shortest path from s
    void shortestPath(long long s, long long k);
};

// Allocates memory for adjacency list
Graph::Graph(long long V) {
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(long long u, long long v, long long w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// Prlong longs shortest paths from src to all other vertices
void Graph::shortestPath(long long src, long long k) {
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<long long> dist(V, INF);

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;

    /* Looping till priority queue becomes empty (or all
    distances are not finalized) */
    while (!pq.empty()) {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        long long u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a
        // vertex
        list<pair<long long, long long> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            // Get vertex label and weight of current
            // adjacent of u.
            long long v = (*i).first;
            long long weight = (*i).second;

            // if (dist[v] > dist[u] + weight) {
            //     // Updating distance of v
            //     if (weight > dist[u]) {
            //         dist[v] = weight;
            //     } else {
            //         dist[v] = dist[u];
            //     }
            //     pq.push(make_pair(dist[v], v));
            // }

            if (dist[v] > weight && dist[v] > dist[u]) {
                dist[v] = max(dist[u], weight);
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Prlong long shortest distances stored in dist[]
    // prlong longf("Vertex Distance from Source\n");
    // for (long long i = 0; i < V; ++i) prlong longf("%d \t\t %d\n", i,
    // dist[i]);

    sort(dist.begin(), dist.end());
    cout << dist[k - 1] << endl;
}

// Driver's code
int main() {
    // create the graph given in above figure
    long long v, m, k;
    cin >> v >> m >> k;
    Graph g(v);

    while (m--) {
        long long a, b, w;
        cin >> a >> b >> w;
        g.addEdge(a - 1, b - 1, w);
    }

    // Function call
    g.shortestPath(0, k);

    return 0;
}