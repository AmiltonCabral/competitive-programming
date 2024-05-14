#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cost = 0;
    string a, b;
    cin >> n >> a >> b;

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (i + 1 < n && a[i + 1] != b[i + 1] && a[i] != a[i + 1]) {
                a[i] = b[i];
                a[i + 1] = b[i + 1];
                cost++;
                i++;
            } else {
                a[i] = (a[i] == '0') ? '1' : '0';
                cost++;
            }
        }
    }

    cout << cost;
}