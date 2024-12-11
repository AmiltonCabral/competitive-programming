#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> left, vector<int> right) {
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    long long totalDistance = 0;

    for (int i = 0; i < left.size(); ++i) {
        totalDistance += abs(left[i] - right[i]);
    }

    cout << totalDistance << endl;
}

int main() {
    ifstream file("input.txt");
    string line;

    vector<int> left, right;

    while (getline(file, line)) {
        istringstream iss(line);
        int nlef, nrig;

        iss >> nlef >> nrig;

        left.push_back(nlef);
        right.push_back(nrig);
    }

    solve(left, right);
}