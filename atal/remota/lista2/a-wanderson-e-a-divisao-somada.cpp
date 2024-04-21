#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<long long> queries;

void calc(vector<ll> vec) {
    if (vec.size() < 1) return;
    if (vec.size() == 1) {
        queries.insert(vec[0]);
        return;
    }
    // verify to avoid infinit loop, ex: vec = [1, 1]
    if (vec[0] == vec.back()) {
        queries.insert(vec[0] * vec.size());
        return;
    }

    long long sum = 0;
    ll mid = (vec[0] + vec.back()) / 2;
    vector<ll> left, right;

    for (ll val : vec) {
        sum += val;

        if (val <= mid)
            left.push_back(val);
        else
            right.push_back(val);
    }

    queries.insert(sum);

    calc(left);
    calc(right);
}

int main() {
    long long t, n, q, si;
    cin >> t;

    while (t--) {
        queries.clear();
        cin >> n >> q;
        vector<ll> vec(n);
        for (ll &value : vec) {
            cin >> value;
        }

        sort(vec.begin(), vec.end());

        // pre *calc* all leaves of the tree and stores them in *queries* map.
        calc(vec);

        while (q--) {
            cin >> si;
            if (queries.count(si))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}