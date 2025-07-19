#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> count;
        for (char ch : magazine) {
            ++count[ch];
        }

        for (char ch : ransomNote) {
            --count[ch];
            if (count[ch] < 0) {
                return false;
            }
        }

        return true;
    }
};