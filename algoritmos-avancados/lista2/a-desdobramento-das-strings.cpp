#include <bits/stdc++.h>
using namespace std;

void resolver(vector<string> &s, map<string, bool> &dic) {
    for (string &s_unit : s) {
        char found = '0';
        for (size_t i = 0; i < s_unit.length(); i++) {
            if (dic[s_unit.substr(0, i + 1)] && dic[s_unit.substr(i + 1)]) {
                found = '1';
                break;
            }
        }
        cout << found;
    }
    cout << endl;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> s(n);
        map<string, bool> dic;
        for (string &s_unit : s) {
            cin >> s_unit;
            dic[s_unit] = true;
        }

        resolver(s, dic);
    }
}