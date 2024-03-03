#include <bits/stdc++.h>
using namespace std;

void solve(queue<pair<int, int>> &tea_q) {
    int second = 0;
    while (!tea_q.empty()) {
        if (second >= tea_q.front().second) {
            cout << 0 << " ";
        } else {
            second = max(second + 1, tea_q.front().first);
            cout << second << " ";
        }
        tea_q.pop();
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        queue<pair<int, int>> tea_q;
        while (n--) {
            int l, r;
            cin >> l >> r;
            tea_q.push({l, r});
        }
        solve(tea_q);
    }
}