#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        vector<long long> cSum(n + 1);

        cin >> a[0];
        cSum[0] = 0;
        cSum[1] = a[0];
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            cSum[i + 1] = a[i] + cSum[i];
            a[i] = max(a[i], a[i - 1]);
        }

        while (q--) {
            int k;
            cin >> k;

            int i = upper_bound(a.begin(), a.end(), k) - a.begin();

            cout << cSum[i] << " ";
        }

        cout << endl;
    }

    return 0;
}