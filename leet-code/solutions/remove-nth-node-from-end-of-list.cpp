#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Time = O(n); Space = O(n)
class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode* node = head;
        while (node) {
            nodes.push_back(node);
            node = node->next;
        }

        // remove first
        if (n == nodes.size()) return head->next;

        if (nodes.size() > nodes.size() - n + 1) {
            nodes[nodes.size() - n - 1]->next = nodes[nodes.size() - n + 1];
        } else {
            nodes[nodes.size() - n - 1]->next = nullptr;
        }

        return head;
    }
};

// But the best way to solve this is with two pointers where you can do it with:
// Space = O(1)