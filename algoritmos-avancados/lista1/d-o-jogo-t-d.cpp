#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &value : a) {
            cin >> value;
        }

        int maxK = 0;

        for (int k = 1; k <= n; k++) {
            multiset<int> aa(a.begin(), a.end());

            for (int i = 0; i < k; i++) {
                auto biggestNum = aa.upper_bound(k - i);
                if (biggestNum == aa.begin()) break;
                aa.erase(--biggestNum);
                if (aa.empty()) break;

                auto lowestNum = *aa.begin();
                aa.erase(aa.begin());
                aa.insert(lowestNum + k - i);
            }

            if (aa.size() + k == n) maxK = k;
        }
        cout << maxK << endl;
    }
}
