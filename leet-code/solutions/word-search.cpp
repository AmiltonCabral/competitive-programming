#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;
        int m = board.size();
        int n = board[0].size();

        function<void(int, int, int)> dfs = [&](int i, int r, int c) {
            if (found) return;
            if (board[r][c] == '#') return;
            if (i == word.size() - 1) {
                found = true;
                return;
            }
            char temp = board[r][c];
            board[r][c] = '#';
            ++i;

            if (r + 1 < m && board[r + 1][c] == word[i]) {
                dfs(i, r + 1, c);
            }
            if (r - 1 >= 0 && board[r - 1][c] == word[i]) {
                dfs(i, r - 1, c);
            }
            if (c + 1 < n && board[r][c + 1] == word[i]) {
                dfs(i, r, c + 1);
            }
            if (c - 1 >= 0 && board[r][c - 1] == word[i]) {
                dfs(i, r, c - 1);
            }
            board[r][c] = temp;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    dfs(0, i, j);
                }
                if (found) {
                    return true;
                }
            }
        }

        return found;
    }
};

int main() {
    // * expect true
    // vector<vector<char>> board = {
    //     {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    // string word = "ABCCED";

    // * expect true
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCESEEEFS";

    bool ans = Solution().exist(board, word);
    cout << (ans ? "true" : "false") << endl;
}