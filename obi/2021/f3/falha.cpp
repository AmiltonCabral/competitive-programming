#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define all(v) v.begin(), v.end()
// #define int long long

// S = len(string); 1 <= S <= 10
// Time: O(N * S^2) => O(N * 10^2) => O(N * 100) => O(N);
signed main() {
    cin.tie(0);  // don't use this line on interactive programs
    ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<string> senhas(N);
    unordered_map<string, int> strCount;

    for (auto& senha : senhas) {
        unordered_set<string> seen;
        cin >> senha;

        // generate all substrings
        for (int i = 0; i < senha.length(); i++) {
            string subStr;
            for (int j = i; j < senha.length(); j++) {
                subStr += senha[j];
                seen.insert(subStr);
            }
        }

        for (const string& str : seen) {
            ++strCount[str];
        }
    }

    int count = -N;

    for (string& senha : senhas) {
        count += strCount[senha];
    }

    cout << count << endl;

    return 0;
}
