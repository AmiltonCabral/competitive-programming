#include <bits/stdc++.h>
using namespace std;

class Trie {
   public:
    unordered_map<char, Trie*> chars;
    bool isWord;

    Trie() { this->isWord = false; }

    // Time: O(L), L = word size
    void insert(string word) {
        Trie* actual = this;
        for (char letter : word) {
            if (!actual->chars.count(letter)) {
                actual->chars[letter] = new Trie();
            }
            actual = actual->chars[letter];
        }
        actual->isWord = true;
    }

    // Time: O(L), L = word size
    bool search(string word) {
        Trie* actual = this;
        for (char letter : word) {
            if (!actual->chars.count(letter)) {
                return false;
            }
            actual = actual->chars[letter];
        }
        return actual->isWord;
    }

    // Time: O(L), L = word size
    bool startsWith(string prefix) {
        Trie* actual = this;
        for (char letter : prefix) {
            if (!actual->chars.count(letter)) {
                return false;
            }
            actual = actual->chars[letter];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */