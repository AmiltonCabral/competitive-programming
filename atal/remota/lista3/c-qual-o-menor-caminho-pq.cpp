#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ipr;
int n;

bool dijkstra(vector<int>& previous) {
    int m;
    cin >> m;

    // creating adjacence list
    vector<vector<ipr>> adjList(n + 1);
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        adjList[a].push_back({b, w});
        adjList[b].push_back({a, w});
    }

    // dijkstra begin ---
    priority_queue<ipr, vector<ipr>, greater<ipr>> pq;
    vector<int> dist(n + 1, INT_MAX);
    vector<bool> explored(n + 1);
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int vOrig = pq.top().second;
        pq.pop();

        if (vOrig == n) return true;

        explored[vOrig] = true;

        for (auto i = adjList[vOrig].begin(); i != adjList[vOrig].end(); i++) {
            int vDest = (*i).first;
            int weight = (*i).second;

            if (!explored[vDest] && dist[vDest] > dist[vOrig] + weight) {
                dist[vDest] = dist[vOrig] + weight;
                pq.push({dist[vDest], vDest});
                previous[vDest] = vOrig;
            }
        }
    }
    return false;
}

int main() {
    cin >> n;
    vector<int> previous(n + 1);

    if (!dijkstra(previous)) {
        cout << "-1";
        return 0;
    }

    vector<int> path;
    int v = n;
    while (v != 1) {
        path.push_back(v);
        v = previous[v];
    }
    path.push_back(1);

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << ' ';
    }
}