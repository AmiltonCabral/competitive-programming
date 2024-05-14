#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> sizes;
    int maxSize = 1;

    void init(int n) {
        parent = vector<int>(n + 1);
        sizes = vector<int>(n + 1, 1);
    }

    void make_set(int v) { parent[v] = v; }

    int find_set(int v) {
        if (parent[v] == v) {
            return v;
        }

        return parent[v] = find_set(parent[v]);
    }

    bool union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            parent[b] = a;
            sizes[a] += sizes[b];
            maxSize = max(maxSize, sizes[a]);
            return true;
        }

        return false;
    }
};

int main() {
    DSU dsu;
    int n, m;
    cin >> n >> m;
    dsu.init(n);
    int componentes = n;

    for (int i = 1; i <= n; i++) {
        dsu.make_set(i);
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        if (dsu.union_set(a, b)) {
            componentes--;
        }

        cout << componentes << ' ' << dsu.maxSize << '\n';
    }
}