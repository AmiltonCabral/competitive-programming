#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        while (lists.size() > 1) {
            vector<ListNode*> mergedl;
            for (int i = 0; i < lists.size(); i += 2) {
                if (i + 1 < lists.size()) {
                    mergedl.push_back(mergeTwoLists(lists[i], lists[i + 1]));
                } else {
                    mergedl.push_back(lists[i]);
                }
            }
            lists = mergedl;
        }

        return lists[0];
    }

   private:
    ListNode* mergeTwoLists(ListNode* la, ListNode* lb) {
        ListNode dummy;
        ListNode* curr = &dummy;

        while (la && lb) {
            if (la->val < lb->val) {
                curr->next = la;
                la = la->next;
            } else {
                curr->next = lb;
                lb = lb->next;
            }
            curr = curr->next;
        }

        if (la) {
            curr->next = la;
        }

        if (lb) {
            curr->next = lb;
        }

        return dummy.next;
    }
};