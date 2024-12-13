#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("input.txt");
    vector<vector<char>> mtx;
    string line;

    while (getline(file, line)) {
        vector<char> row(line.begin(), line.end());
        mtx.push_back(row);
    }

    int count = 0;
    int m = mtx.size();
    int n = mtx[0].size();

    // left -> right | right -> left
    for (auto& row : mtx) {
        for (int j = 0; j < n - 3; ++j) {
            string word(row.begin() + j, row.begin() + j + 4);

            if (word == "XMAS") ++count;
            if (word == "SAMX") ++count;
        }
    }

    // top -> down | down -> top
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m - 3; ++i) {
            string word = string() + mtx[i][j] + mtx[i + 1][j] + mtx[i + 2][j] +
                          mtx[i + 3][j];

            if (word == "XMAS") ++count;
            if (word == "SAMX") ++count;
        }
    }

    for (int i = 0; i < m - 3; ++i) {
        for (int j = 0; j < n - 3; ++j) {
            // top.left -> bot.right
            string word = string() + mtx[i][j] + mtx[i + 1][j + 1] +
                          mtx[i + 2][j + 2] + mtx[i + 3][j + 3];

            if (word == "XMAS") ++count;
            if (word == "SAMX") ++count;

            // top.right -> bot.left
            word = string() + mtx[i][j + 3] + mtx[i + 1][j + 2] +
                   mtx[i + 2][j + 1] + mtx[i + 3][j];

            // cout << "i: " << i << ", j: " << j << ", word: " << word << endl;

            if (word == "XMAS") ++count;
            if (word == "SAMX") ++count;
        }
    }

    cout << count << endl;
}
