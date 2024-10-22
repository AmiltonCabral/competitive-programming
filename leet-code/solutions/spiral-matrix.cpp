#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int limit_top = 0;
        int limit_bot = matrix.size();
        int limit_lef = -1;
        int limit_rig = matrix[0].size();

        int missing = matrix.size() * matrix[0].size();
        char direction = 'r';
        int r = 0, c = 0;
        vector<int> ans;

        while (missing) {
            ans.push_back(matrix[r][c]);
            --missing;

            switch (direction) {
                case 'r':
                    if (c + 1 < limit_rig) {
                        ++c;
                    } else {
                        ++r;
                        direction = 'b';
                        --limit_rig;
                    }
                    break;

                case 'b':
                    if (r + 1 < limit_bot) {
                        ++r;
                    } else {
                        --c;
                        direction = 'l';
                        --limit_bot;
                    }
                    break;

                case 'l':
                    if (c - 1 > limit_lef) {
                        --c;
                    } else {
                        --r;
                        direction = 't';
                        ++limit_lef;
                    }
                    break;

                case 't':
                    if (r - 1 > limit_top) {
                        --r;
                    } else {
                        ++c;
                        direction = 'r';
                        ++limit_top;
                    }
                    break;
            }
        }

        return ans;
    }
};