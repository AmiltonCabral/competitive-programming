#include <bits/stdc++.h>
using namespace std;

int n;

int vMinDistance(vector<int>& dist, vector<bool>& explored) {
    int minVec;
    int minVecDist = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (!explored[i] && dist[i] < minVecDist) {
            minVecDist = dist[i];
            minVec = i;
        }
    }
    return minVec;
}

bool dijkstra(vector<int>& previous) {
    int m;
    cin >> m;

    // creating adjacence list
    vector<vector<pair<int, int>>> adjList(n + 1);
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        adjList[a].push_back({b, w});
        adjList[b].push_back({a, w});
    }

    vector<int> dist(n + 1, INT_MAX);
    vector<bool> explored(n + 1);
    dist[1] = 0;

    for (int count = 1; count <= n; count++) {
        int vOrig = vMinDistance(dist, explored);
        explored[vOrig] = true;

        if (explored[n]) return true;

        for (auto i = adjList[vOrig].begin(); i != adjList[vOrig].end(); i++) {
            int vDest = (*i).first;
            int weight = (*i).second;

            if (!explored[vDest] && dist[vDest] > dist[vOrig] + weight) {
                dist[vDest] = dist[vOrig] + weight;
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