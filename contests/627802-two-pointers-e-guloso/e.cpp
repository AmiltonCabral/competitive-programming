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

    int n, k;
    string str;
    cin >> n >> k >> str;

    // only 'a'
    int l = 0, r = 0, changes = 0, ans = 0;
    while (r < n) {
        if (str.at(r) == 'b') {
            ++changes;
        }
        while (changes > k) {
            if (str.at(l) == 'b') {
                --changes;
            }
            ++l;
        }
        ans = max(ans, r - l + 1);
        ++r;
    }

    // only 'b'
    l = 0, r = 0, changes = 0;
    while (r < n) {
        if (str.at(r) == 'a') {
            ++changes;
        }
        while (changes > k) {
            if (str.at(l) == 'a') {
                --changes;
            }
            ++l;
        }
        ans = max(ans, r - l + 1);
        ++r;
    }

    cout << ans << endl;
}