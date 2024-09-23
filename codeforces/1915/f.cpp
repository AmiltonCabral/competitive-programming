#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>
    ordered_set;

void solve(vector<pair<int, int>> &arr) {
    sort(arr.begin(), arr.end());

    long long ans = 0;
    ordered_set st;

    for (pair<int, int> pr : arr) {
        int index = st.order_of_key(pr.second);
        ans += st.size() - index;
        st.insert(pr.second);
    }

    cout << ans << '\n';
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> arr(n);

        for (auto &pr : arr) {
            cin >> pr.first >> pr.second;
        }

        solve(arr);
    }
}