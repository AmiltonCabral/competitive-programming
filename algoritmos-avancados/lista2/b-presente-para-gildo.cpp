#include <bits/stdc++.h>
using namespace std;

// gwakijpffrsq -> affpjikrsqwg

int main() {
    string s, t, u;
    cin >> s;

    vector<int> big_reg(s.length());
    big_reg[s.length() - 1] = s.length() - 1;
    for (int i = s.length() - 2; i >= 0; i--) {
        big_reg[i] = s[i] < s[big_reg[i + 1]] ? i : big_reg[i + 1];
    }

    for (int i = 0; i < s.length(); i++) {
        while (!t.empty() && t.back() <= s[big_reg[i]]) {
            u.push_back(t.back());
            t.pop_back();
        }

        if (i == big_reg[i]) {
            u.push_back(s[i]);
        } else {
            t.push_back(s[i]);
        }
    }

    while (!t.empty()) {
        u.push_back(t.back());
        t.pop_back();
    }

    cout << u << endl;
}
