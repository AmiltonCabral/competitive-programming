#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    /*
     Input: ["neet","code","love","you"]
     :4:4:4:3-neetcodeloveyou
     "4:4:4:3" is the size of each str

     Time: O(N * L), where N is size of strs and L is size of each str in strs.
     Space: O(N * L)
    */
    string encode(vector<string>& strs) {
        string prefix = "";
        string conc = "";
        for (string str : strs) {
            conc += str;
            prefix += ':' + to_string(str.size());
        }
        return prefix + '-' + conc;
    }

    // Time: O(N * L)
    // Space: O(N * L)
    vector<string> decode(string s) {
        int prefSize;
        for (int i = 0; i < s.size(); ++i) {
            if (s.at(i) == '-') {
                prefSize = i + 1;
                break;
            }
        }

        vector<string> deco;
        int currStart = prefSize;
        string currSize = "";

        for (int i = 1; i <= prefSize && i < s.size(); ++i) {
            if (s.at(i) == ':' || s.at(i) == '-') {
                int iCurrSize = stoi(currSize);
                deco.push_back(s.substr(currStart, iCurrSize));
                currStart += iCurrSize;
                currSize = "";
            } else {
                currSize += s.at(i);
            }
        }

        return deco;
    }
};

int main() {
    Solution sol;

    // {""}; {}; {"Hello", "", "world"}; {"we","say",":","yes"};
    vector<string> input = {"neet", "code", "love", "you"};

    string encoded = sol.encode(input);
    cout << "Encoded string = " << encoded << endl;
    vector<string> output = sol.decode(encoded);
    cout << endl;
}
