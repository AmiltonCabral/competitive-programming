#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};

// last recently used are put at the beggining
class LRUCache {
   public:
    unordered_map<int, Node*> cache;
    Node* first;
    Node* last;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        first = new Node(0, 0);
        last = new Node(0, 0);
        first->next = last;
        last->prev = first;
    }

    Node* remove(int key) {
        Node* node = cache[key];
        if (!node) {
            return nullptr;
        }

        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = node->next;
        next->prev = node->prev;

        cache.erase(key);

        return node;
    }

    void addToEnd(Node* node) {
        Node* prev = last->prev;

        node->prev = prev;
        node->next = last;
        prev->next = node;
        last->prev = node;

        cache[node->key] = node;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        Node* node = remove(key);
        addToEnd(node);

        return node->val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(key);
        }

        Node* node = new Node(key, value);
        addToEnd(node);

        if (cache.size() > cap) {
            remove(first->next->key);
        }
    }
};

int main() {
    LRUCache cache(2);

    cache.put(2, 1);
    cache.put(1, 1);
    cache.put(2, 3);
    cache.put(4, 1);

    cout << cache.get(1) << endl;  // returns 1
    cout << cache.get(2) << endl;  // returns 3
    return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
