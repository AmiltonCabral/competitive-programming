#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define all(v) v.begin(), v.end()
// #define int long long

signed main() {
    cin.tie(0);  // don't use this line on interactive programs
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    if (n == 1) {
        cout << "1 0" << endl;
        return 0;
    }

    vector<int> table(n);
    for (int& choc : table) {
        cin >> choc;
    }

    int l = 0;
    int r = n - 1;
    int alice = 1;
    int bob = 1;

    while (l < r - 1) {
        if (table[l] < table[r]) {
            table[r] -= table[l];
            ++l;
            ++alice;
        } else if (table[l] > table[r]) {
            table[l] -= table[r];
            --r;
            ++bob;
        } else {
            ++l;
            --r;
            if (l == r) {
                ++alice;
            } else {
                ++alice;
                ++bob;
            }
        }
    }

    cout << alice << ' ' << bob << endl;
}