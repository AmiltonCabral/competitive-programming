#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, b1, b2;
    cin >> t;

    while (t--) {
        cin >> b1 >> b2;

        if ((b1 + b2) % 2 == 1) {
            cout << "-1 -1" << endl;
            continue;
        }

        int target = (b1 + b2) / 2;
        int c1, c2;

        if (b1 > b2) {
            c1 = b1 - target;
            c2 = b2;
        } else {
            c2 = b2 - target;
            c1 = b1;
        }

        cout << c1 << " " << c2 << endl;
    }
}