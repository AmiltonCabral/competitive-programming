#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// calcula maior retangulo em um histograma
void solve(vector<int> &builds) {
    long long max_rect = 0;
    vector<int> del_l(builds.size());
    vector<int> del_r(builds.size());
    vector<int> stack;
    int i;

    // calcula delimitador direita
    stack.push_back(0);
    for (i = 1; i < builds.size(); i++) {
        while (!stack.empty() && builds[i] < builds[stack.back()]) {
            del_r[stack.back()] = i - 1;
            stack.pop_back();
        }
        stack.push_back(i);
    }

    while (!stack.empty()) {
        del_r[stack.back()] = i - 1;
        stack.pop_back();
    }

    // calcula delimitador esquerda
    stack.push_back(builds.size() - 1);
    for (i = builds.size() - 2; i >= 0; i--) {
        while (!stack.empty() && builds[i] < builds[stack.back()]) {
            del_l[stack.back()] = i + 1;
            stack.pop_back();
        }
        stack.push_back(i);
    }

    while (!stack.empty()) {
        del_l[stack.back()] = i + 1;
        stack.pop_back();
    }

    // calcula quanto pode ir pra esquerda e direita, e multiplica pela altura
    for (i = 0; i < builds.size(); i++) {
        long long act_rect = (del_r[i] - del_l[i] + 1LL) * builds[i];
        max_rect = max(max_rect, act_rect);
    }

    cout << max_rect << endl;
}

int main() {
    int n;
    cin >> n;
    while (n > 0) {
        vector<int> builds(n);
        for (int &hi : builds) {
            cin >> hi;
        }

        solve(builds);

        cin >> n;
    }
}

// len:       2 1 4 5 1 3 3
// del_r:     0 6 3 3 6 6 6
// del_l:     0 0 2 3 0 5 5
// width:     1 7 2 1 7 2 2
// wid * len: 2 7 8 5 7 6 6