#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define all(v) v.begin(), v.end()
// #define int long long

int solve(vector<int>& plants, int k) {
    int l = 0, r = 1, minp = plants[0], maxp = plants[0];
    while (r < k && r < plants.size()) {
        minp = min(minp, plants[r]);
        maxp = max(maxp, plants[r]);
        ++r;
    }

    int ans = maxp - minp;

    while (r < plants.size()) {
        minp = plants[l];
        maxp = minp;
        for (int i = l; i <= r; ++i) {
            minp = min(minp, plants[i]);
            maxp = max(maxp, plants[i]);
        }
        ++l;
        ++r;
        ans = max(ans, maxp - minp);
    }

    return ans;
}

signed main() {
    // cin.tie(0);  // don't use this line on interactive programs
    ios_base::sync_with_stdio(0);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> plants(n);
        for (int& plant : plants) {
            cin >> plant;
        }
        cout << solve(plants, k) << endl;
    }
}