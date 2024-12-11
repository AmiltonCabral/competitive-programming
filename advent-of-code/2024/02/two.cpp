#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int> arr) {
    bool increasing = false;
    bool decreasing = false;

    for (int i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] < arr[i + 1]) {
            increasing = true;
        } else {
            decreasing = true;
        }

        if (increasing && decreasing) {
            return false;
        }

        int diff = abs(arr[i] - arr[i + 1]);
        if (diff > 3 || diff == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    ifstream file("input.txt");
    string line;
    int reportsSafe = 0;

    while (getline(file, line)) {
        istringstream iss(line);
        vector<int> arr;
        int num;

        while (iss >> num) {
            arr.push_back(num);
        }

        bool safe = isSafe(arr);
        for (int i = 0; i < arr.size() && !safe; ++i) {
            vector<int> copy = arr;
            copy.erase(copy.begin() + i);
            safe = isSafe(copy);
        }

        if (safe) {
            ++reportsSafe;
        }
    }

    cout << reportsSafe << endl;
}