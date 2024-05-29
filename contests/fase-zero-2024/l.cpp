#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define all(v) v.begin(), v.end()
// #define int long long

signed main() {
    // cin.tie(0);  // don't use this line on interactive programs
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    vector<string> child(n);
    vector<int> irr(n);
    unordered_map<string, int> rooms;
    unordered_map<int, string> irrmap;

    for (int i = 0; i < n; ++i) {
        cin >> child[i];
        rooms[child[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        string crianca;
        cin >> crianca;
        irr[rooms[crianca]] = i;
        irrmap[i] = crianca;
    }

    vector<int> ans(n);
    ans[n - 1] = irr[rooms[child[n - 1]]];
    for (int i = n - 2; i >= 0; --i) {
        ans[i] = min(ans[i + 1], irr[rooms[child[i]]]);
    }

    for (int i = 0; i < irrmap.size(); i++) {
        cout << irrmap[ans[i]];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
}