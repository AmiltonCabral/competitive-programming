#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> id(n);
    for (int i = 0; i < n; i++) {
        cin >> id[i];
    }

    if (k == 1) {
        cout << id[0] << endl;
        return 0;
    }

    long long current_k = 1;
    for (int i = 1; i < n; i++) {
        current_k += i + 1;

        if (current_k >= k) {
            cout << id[i - (current_k - k)] << endl;
            break;
        }
    }

    return 0;
}