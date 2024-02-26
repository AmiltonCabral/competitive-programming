#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> k(n);
    map<int, int> k_count;
    for (int &num : k) cin >> num;

    int l = 0, r = 0, count = 0, max_count = 0;

    while (r < n) {
        k_count[k[r]]++;
        count++;

        while (k_count[k[r]] > 1) {
            k_count[k[l++]]--;
            count--;
        }

        max_count = max(count, max_count);

        r++;
    }

    cout << max_count << endl;
}
