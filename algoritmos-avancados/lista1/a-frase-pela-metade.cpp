#include <bits/stdc++.h>
using namespace std;

int goodString(string s, char c) {
    if (s.size() <= 1) {
        return s[0] == c ? 0 : 1;
    }
    int mid = s.size() / 2;
    string beginS = string(s.begin(), s.end() - mid);
    string endS = string(s.begin() + mid, s.end());

    int countL = goodString(beginS, c + 1);
    int countR = goodString(endS, c + 1);

    countL += mid - count(s.begin() + mid, s.end(), c);
    countR += mid - count(s.begin(), s.end() - mid, c);

    return min(countL, countR);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << goodString(s, 'a') << endl;
    }
    return 0;
}