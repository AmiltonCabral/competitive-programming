#include <iostream>
using namespace std;

void processList(int n, int x) {
    long long a[n], b[n], sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        sum += a[i];
    }

    int i = 0;
    while (a[i] % x == 0) {
        sum += b[i];
        a[i] = a[i] / x;

        i = (i + 1) % n;
    }

    cout << sum << endl;
}

int main() {
    int t, n, x;
    cin >> t;

    while (t--) {
        cin >> n >> x;
        processList(n, x);
    }

    return 0;
}