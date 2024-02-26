#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    map<int, vector<int>> a;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[num].push_back(i + 1);
    }

    int x, k, ans;
    while (q--) {
        ans = -1;
        cin >> x >> k;

        if (!a[x].empty() && a[x].size() >= k) {
            ans = a[x][k - 1];
        }
        cout << ans << endl;
    }

    return 0;
}