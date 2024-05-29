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
    cin.tie(0);  // don't use this line on interactive programs
    ios_base::sync_with_stdio(0);

    int r;
    cin >> r;
    vector<int> arr(r);
    for (int& num : arr) {
        cin >> num;
    }

    int l = 0;
    --r;
    ll sum1 = 0, sum3 = 0, ans = 0;

    while (l <= r) {
        if (sum1 < sum3) {
            sum1 += arr[l];
            ++l;
        } else {
            sum3 += arr[r];
            --r;
        }
        if (sum1 == sum3) {
            ans = sum1;
        }
    }
    cout << ans << endl;
}