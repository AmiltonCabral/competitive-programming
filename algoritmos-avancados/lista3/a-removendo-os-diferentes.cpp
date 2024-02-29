#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        priority_queue<pair<int, int>> a;
        map<int, int> count_a;

        while (n--) {
            int num;
            cin >> num;
            count_a[num]++;
        }

        for (auto &val : count_a) {
            a.push({val.second, val.first});
        }

        while (a.size() > 1) {
            pair<int, int> first_hi = a.top();
            a.pop();
            pair<int, int> secon_hi = a.top();
            a.pop();
            first_hi.first--;
            secon_hi.first--;

            if (first_hi.first > 0) {
                a.push(first_hi);
            }
            if (secon_hi.first > 0) {
                a.push(secon_hi);
            }
        }

        if (a.empty()) {
            cout << 0 << endl;
        } else {
            cout << a.top().first << endl;
        }
    }
}