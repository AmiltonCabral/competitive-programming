#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int depth, int left, int right) {
    if (left > right) return;
    if (left == right) {
        arr[left] = depth;
        return;
    }

    int maxEl = arr[left];
    int idxMaxEl = left;
    for (int i = left + 1; i <= right; ++i) {
        if (arr[i] > maxEl) {
            maxEl = arr[i];
            idxMaxEl = i;
        }
    }

    arr[idxMaxEl] = depth++;

    solve(arr, depth, left, idxMaxEl - 1);
    solve(arr, depth, idxMaxEl + 1, right);
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> arr(n);

        for (int &el : arr) {
            cin >> el;
        }

        solve(arr, 0, 0, n - 1);

        for (int i = 0; i < n; ++i) {
            cout << arr[i];
            if (i < n - 1) {
                cout << ' ';
            } else {
                cout << '\n';
            }
        }
    }
}
