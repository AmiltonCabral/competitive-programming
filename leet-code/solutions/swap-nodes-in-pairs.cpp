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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = head->next;
        ListNode* prev = new ListNode(0, head);
        ListNode* curr = head;

        while (curr && curr->next) {
            // save ptrs
            ListNode* secd = curr->next;
            ListNode* nextIt = secd->next;

            // swap
            prev->next = secd;
            secd->next = curr;
            curr->next = nextIt;

            // update ptrs
            prev = curr;
            curr = nextIt;
        }

        return newHead;
    }
};