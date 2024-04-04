#include <bits/stdc++.h>
using namespace std;

int n, m, k;
char moves[] = {'L', 'R', 'T', 'D'};

void printMatrix(vector<vector<char>> &matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

bool isValidMove(vector<vector<char>> &matrix, pair<int, int> pos, char move) {
    if (move == 'T' && pos.first - 1 >= 0 &&
        matrix[pos.first - 1][pos.second] == '.')
        return true;
    if (move == 'D' && pos.first + 1 < n &&
        matrix[pos.first + 1][pos.second] == '.')
        return true;
    if (move == 'L' && pos.second - 1 >= 0 &&
        matrix[pos.first][pos.second - 1] == '.')
        return true;
    if (move == 'R' && pos.second + 1 < m &&
        matrix[pos.first][pos.second + 1] == '.')
        return true;
    return false;
}

// comeca de um caminho vazio e anda até s - k (s == caminhos
// vazios) as celulas restantes devem ser preenchidas com #
bool bt(vector<vector<char>> &matrix, int &dots, pair<int, int> pos, int i) {
    if (i == dots - k) return true;

    for (char move : moves) {
        if (i + 1 == dots - k || isValidMove(matrix, pos, move)) {
            pair<int, int> newPos;
            if (move == 'T') {
                newPos.first = pos.first - 1;
                newPos.second = pos.second;
            }
            if (move == 'D') {
                newPos.first = pos.first + 1;
                newPos.second = pos.second;
            }
            if (move == 'L') {
                newPos.first = pos.first;
                newPos.second = pos.second - 1;
            }
            if (move == 'R') {
                newPos.first = pos.first;
                newPos.second = pos.second + 1;
            }

            matrix[pos.first][pos.second] = '0';
            if (bt(matrix, dots, newPos, i + 1)) return true;
            matrix[pos.first][pos.second] = '.';
        }
    }
    return false;
}

int main() {
    cin >> n >> m >> k;
    vector<vector<char>> matrix(n, vector<char>(m));
    int numDots = 0;
    pair<int, int> firstDot;

    char actualChar;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> actualChar;
            matrix[i][j] = actualChar;
            if (actualChar == '.') {
                numDots++;
                firstDot = {i, j};
            }
        }
    }

    bt(matrix, numDots, firstDot, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.') {
                matrix[i][j] = 'X';
            } else if (matrix[i][j] == '0') {
                matrix[i][j] = '.';
            }
        }
    }

    printMatrix(matrix);
}