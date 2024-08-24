#include <bits/stdc++.h>
using namespace std;

string abbreviation(string a, string b) {
    bool possible = false;
    unordered_set<string> memo;

    function<void(string, string)> isAbbreviation = [&](string aa, string bb) {
        if (possible || aa.size() < bb.size()) return;
        if (bb.empty()) {
            for (char ch : aa) {
                if (isupper(ch)) return;
            }
            possible = true;
            return;
        }

        // Memorization
        string tag = aa + '#' + bb;
        if (memo.count(tag)) return;
        memo.insert(tag);

        char nextChar = aa[0];
        aa.erase(0, 1);
        if (islower(nextChar))
            isAbbreviation(aa, bb);  // path that consume lower
        if (toupper(nextChar) != bb[0]) return;
        bb.erase(0, 1);
        isAbbreviation(aa, bb);  // path that consume upper
    };

    isAbbreviation(a, b);

    return possible ? "YES" : "NO";
}

int main() {
    string a = "daBcd";
    string b = "ABC";
    string ans = abbreviation(a, b);
    cout << ans << endl;
}