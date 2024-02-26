#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    long long sum_current = x[0], max_global = x[0];

    for (int i = 1; i < n; i++) {
        sum_current = x[i] > x[i] + sum_current ? x[i] : x[i] + sum_current;
        max_global = max_global > sum_current ? max_global : sum_current;
    }

    cout << max_global << endl;

    return 0;
}