#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cubes(n);

    for (int &cube : cubes) {
        cin >> cube;
    }

    vector<int> towers;

    for (int cube : cubes) {
        auto it = lower_bound(towers.begin(), towers.end(), cube,
                              [](int a, int b) { return a <= b; });
        int index = it - towers.begin();
        if (index == towers.size()) {
            towers.push_back(cube);
        } else {
            towers[index] = cube;
        }
    }

    cout << towers.size() << endl;
}