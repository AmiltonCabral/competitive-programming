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

class Solution {
   public:
    pair<ListNode*, ListNode*> getTail(ListNode* head) {
        ListNode* lb = head;
        ListNode* l = head->next;
        while (l->next) {
            lb = l;
            l = lb->next;
        }
        return {lb, l};
    }

    void reorderList(ListNode* head) {
        ListNode* a = head;
        while (a && a->next && a->next->next) {
            ListNode* b = a->next;
            pair<ListNode*, ListNode*> l = getTail(a);

            l.second->next = b;
            a->next = l.second;
            l.first->next = nullptr;
            a = a->next->next;
        }
    }
};