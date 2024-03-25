#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<int, pair<int, int>> count_wins(vector<int> &arr, int max_rounds) {
    map<int, pair<int, int>> wins;
    int l = 0, r = 1, round = 1;
    while (r < max_rounds) {
        if (arr[r] > arr[l]) {
            wins[r].first++;
            wins[r].second = round;
            l = r;
        } else {
            wins[l].first++;
            wins[l].second = round;
        }
        r++;
        round++;
    }
    return wins;
}

int main() {
    int t, n, q, i, rounds, stronger = 0;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        vector<int> a(n);

        for (int &num : a) {
            cin >> num;
            stronger = max(num, stronger);
        }

        // index_fighter: {wins, max_round}
        map<int, pair<int, int>> wins = count_wins(a, n);

        while (q--) {
            cin >> i >> rounds;
            i--;

            if (wins[i].first == 0) {
                cout << 0 << endl;
                continue;
            }

            if (wins[i].second <= rounds) {
                if (a[i] == stronger) {
                    cout << (wins[i].first + (rounds - wins[i].second)) << endl;
                } else {
                    cout << wins[i].first << endl;
                }
            } else {
                cout << (wins[i].first - (wins[i].second - rounds)) << endl;
            }
        }
    }
}