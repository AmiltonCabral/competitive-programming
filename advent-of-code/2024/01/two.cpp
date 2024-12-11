#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> left, unordered_map<int, int> right) {
    long long totalDistance = 0;

    for (int i = 0; i < left.size(); ++i) {
        totalDistance += left[i] * right[left[i]];
    }

    cout << totalDistance << endl;
}

int main() {
    ifstream file("input.txt");
    string line;

    vector<int> left;
    unordered_map<int, int> right;

    while (getline(file, line)) {
        istringstream iss(line);
        int nlef, nrig;

        iss >> nlef >> nrig;

        left.push_back(nlef);
        ++right[nrig];
    }

    solve(left, right);
}