#include <bits/stdc++.h>
using namespace std;

#define int long long

// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B

void solve(vector<int> &arr, int query, int l, int r) {
    if (l == r) {
        while (l + 1 < arr.size() && arr[l + 1] == query) ++l;
        if (query == arr[l]) ++l;

        cout << l << endl;
        return;
    }

    int mid = (l + r) / 2;

    if (query <= arr[mid]) {
        solve(arr, query, l, mid);
    } else {
        solve(arr, query, mid + 1, r);
    }
}

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &ai : arr) cin >> ai;

    while (k--) {
        int query;
        cin >> query;
        solve(arr, query, 0, n);
    }
}
