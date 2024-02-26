#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<long long> sum_prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        sum_prefix[i] = sum_prefix[i - 1] + x[i - 1];
    }

    for (int _ = 0; _ < q; ++_) {
        int a, b;
        cin >> a >> b;
        cout << (sum_prefix[b] - sum_prefix[a - 1]) << endl;
    }

    return 0;
}
