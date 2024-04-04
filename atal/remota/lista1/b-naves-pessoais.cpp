#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, l, r;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        if (r - l >= 100) {
            while (l % 100 != 90) l++;
            cout << l << endl;
            continue;
        }
        string lStr = to_string(l);
        string best = lStr;
        char minVal = lStr[0];
        char maxVal = lStr[0];

        for (int i = l; i <= r; i++) {
            lStr = to_string(i);
            char actMinVal = lStr[0];
            char actMaxVal = lStr[0];
            for (char el : lStr) {
                actMinVal = min(el, actMinVal);
                actMaxVal = max(el, actMaxVal);
            }
            if (actMaxVal - actMinVal > maxVal - minVal) {
                minVal = actMinVal;
                maxVal = actMaxVal;
                best = lStr;
            }
        }

        cout << best << endl;
    }
}
