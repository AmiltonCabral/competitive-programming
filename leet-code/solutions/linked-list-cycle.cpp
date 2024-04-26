#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *slowest = head, *fastest = head->next;
        int i = 0, maxSize = 10001;
        while (i < maxSize) {
            if (!fastest || !fastest->next) return false;
            if (slowest == fastest) {
                return true;
            }
            i++;
            slowest = slowest->next;
            fastest = fastest->next->next;
        }
        return false;
    }
};
