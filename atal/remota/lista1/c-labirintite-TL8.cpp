#include <bits/stdc++.h>
using namespace std;

int n, m, k;

bool isValidMtx(vector<vector<char>> &matrix, vector<pair<char, char>> &dots) {
    int sumDots = 0;
    for (pair<char, char> dot : dots) {
        if (matrix[dot.first][dot.second] == 'X') continue;
        sumDots++;

        if (dot.first + 1 < n && matrix[dot.first + 1][dot.second] == '.')
            return true;
        if (dot.first - 1 >= 0 && matrix[dot.first - 1][dot.second] == '.')
            return true;
        if (dot.second + 1 < m && matrix[dot.first][dot.second + 1] == '.')
            return true;
        if (dot.second - 1 >= 0 && matrix[dot.first][dot.second - 1] == '.')
            return true;
    }
    if (sumDots <= 1) return true;
    return false;
}

void printMatrix(vector<vector<char>> &matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

bool bt(vector<vector<char>> &matrix, vector<pair<char, char>> &dots, int i,
        int added) {
    if (!isValidMtx(matrix, dots)) return false;
    if (i >= dots.size()) return false;
    if (added == k) {
        printMatrix(matrix);
        return true;
    }

    matrix[dots[i].first][dots[i].second] = 'X';
    if (bt(matrix, dots, i + 1, added + 1)) return true;
    matrix[dots[i].first][dots[i].second] = '.';
    if (bt(matrix, dots, i + 1, added)) return true;

    return false;
}

int main() {
    cin >> n >> m >> k;
    vector<vector<char>> matrix(n, vector<char>(m));
    vector<pair<char, char>> dots;

    char actualChar;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> actualChar;
            matrix[i][j] = actualChar;
            if (actualChar == '.') dots.push_back({i, j});
        }
    }

    bt(matrix, dots, 0, 0);
}