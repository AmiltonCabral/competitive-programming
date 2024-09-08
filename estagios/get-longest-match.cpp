#include <bits/stdc++.h>
using namespace std;

int getLongestMatch(string text, string regex) {
    int n = text.size();
    string pref = "";
    string sufi = "";

    for (int i = 0; i < regex.size(); ++i) {
        if (regex[i] == '*') {
            ++i;
            while (i < regex.size()) {
                sufi += regex[i];
                ++i;
            }
            break;
        };
        pref += regex[i];
    }

    int pl = 0, pr = pref.size() - 1;

    while (pr <= n && text.substr(pl, pref.size()) != pref) {
        ++pl;
        ++pr;
    }

    if (text.substr(pl, pref.size()) != pref) {
        return -1;
    }

    int sl = n - sufi.size(), sr = n;

    while (sl > pr && text.substr(sl, sufi.size()) != sufi) {
        --sl;
        --sr;
    }

    if (text.substr(sl, sufi.size()) != sufi) {
        return -1;
    }

    return sr - pl;
}

int main() {
    string text = "hackerrank";
    string regex = "ack*r";
    cout << getLongestMatch(text, regex) << endl;
}