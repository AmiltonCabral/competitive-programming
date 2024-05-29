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
    cin.tie(0);  // don't use this line on interactive programs
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    list<int> cards;

    while (n--) {
        int card;
        cin >> card;
        cards.pb(card);
    }

    int players[2] = {};
    int turn = 1;

    while (!cards.empty()) {
        if (cards.front() > cards.back()) {
            players[(turn + 1) % 2] += cards.front();
            cards.pop_front();
        } else {
            players[(turn + 1) % 2] += cards.back();
            cards.pop_back();
        }
        ++turn;
    }

    cout << players[0] << ' ' << players[1] << endl;
}