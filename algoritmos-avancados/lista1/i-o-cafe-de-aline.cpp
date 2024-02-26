#include <bits/stdc++.h>
#define ArrS 200002
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> recipes(ArrS);

    while (n--) {
        int l, r;
        cin >> l >> r;
        recipes[l]++;
        recipes[r + 1]--;
    }

    for (int i = 1; i < ArrS; i++) {
        recipes[i] += recipes[i - 1];
        recipes[i - 1] = recipes[i - 1] >= k ? 1 : 0;
        recipes[i - 1] += recipes[i - 2];
    }

    for (int i = 0; i < q; i++) {
        int a, b, num_adm;
        cin >> a >> b;
        num_adm = recipes[b] - recipes[a - 1];
        cout << num_adm << endl;
    }

    return 0;
}