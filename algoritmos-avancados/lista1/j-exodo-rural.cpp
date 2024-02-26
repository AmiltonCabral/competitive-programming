#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, zeros = 0;
    cin >> n >> k;

    vector<int> cumuSum(n);
    string rooms;
    cin >> rooms;

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (rooms[i] == '0') {
            cumuSum[j++] = i;
            zeros++;
        }
    }

    int minDist = INT_MAX;

    for (int l = 0; l < zeros - k; l++) {
        int r = l + k;

        for (int f = l; f <= r; f++) {
            if (cumuSum[r] - cumuSum[f] > cumuSum[f] - cumuSum[l]) {
                if (cumuSum[r] - cumuSum[f] < minDist) {
                    minDist = cumuSum[r] - cumuSum[f];
                }
            } else {
                if (cumuSum[f] - cumuSum[l] < minDist) {
                    minDist = cumuSum[f] - cumuSum[l];
                }
            }
        }
    }

    cout << minDist << endl;

    return 0;
}