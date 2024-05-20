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
    // cin.tie(0);  // don't use this line on interactive programs
    ios_base::sync_with_stdio(0);

    double D;
    int N, L;
    cin >> N >> L >> D;
    D /= 1000;

    int goal = N * D;
    int coffee = goal / L;
    coffee *= L;
    if (fmod(N * D, L) > 0) {
        coffee += L;
    }

    cout << coffee << endl;

    return 0;
}