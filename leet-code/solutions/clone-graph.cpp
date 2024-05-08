#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> copies;
        queue<Node*> q;
        Node* rootCopy = new Node(node->val);
        copies[node] = rootCopy;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            for (Node* neighbor : current->neighbors) {
                if (!copies.count(neighbor)) {
                    Node* neighborCopy = new Node(neighbor->val);
                    copies[neighbor] = neighborCopy;
                    q.push(neighbor);
                }

                copies[current]->neighbors.push_back(copies[neighbor]);
            }
        }

        return rootCopy;
    }
};
