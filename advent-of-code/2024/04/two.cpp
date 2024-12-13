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

    // top -> down | down -> top
    for (int j = 0; j < n - 2; ++j) {
        for (int i = 0; i < m - 2; ++i) {
            bool lvalid = false;
            bool rvalid = false;

            // top.left -> bot.right
            string lword =
                string() + mtx[i][j] + mtx[i + 1][j + 1] + mtx[i + 2][j + 2];

            if (lword == "MAS") lvalid = true;
            if (lword == "SAM") lvalid = true;

            // top.right -> bot.left
            string rword =
                string() + mtx[i][j + 2] + mtx[i + 1][j + 1] + mtx[i + 2][j];

            if (rword == "MAS") rvalid = true;
            if (rword == "SAM") rvalid = true;

            if (lvalid && rvalid) ++count;
        }
    }

    cout << count << endl;
}
