#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        int ans = 0;

        for (int k = 1; k <= n; ++k) {
            multiset<int> s(a.begin(), a.end());

            for (int i = 0; i < k; ++i) {
                auto it = s.upper_bound(k - i);
                if (it == s.begin()) break;
                s.erase(--it);
                if (!s.empty()) {
                    int x = *s.begin();
                    s.erase(s.begin());
                    s.insert(x + k - i);
                }
            }
            if (s.size() + k == n) ans = k;
        }
        cout << ans << '\n';
    }
}