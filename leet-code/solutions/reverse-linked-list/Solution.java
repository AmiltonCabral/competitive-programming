package reverselinkedlist;

import java.util.LinkedList;
import java.util.Stack;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        Stack<Integer> stack = new Stack<Integer>();
        ListNode reversedList = new ListNode();
        ListNode reversedListHead = reversedList;

        while (head != null) {
            stack.push(head.val);
            head = head.next;
        }

        if (!stack.isEmpty()) {
            reversedList.val = stack.pop();
        } else {
            return null;
        }

        while (!stack.isEmpty()) {
            reversedList.next = new ListNode(stack.pop());
            reversedList = reversedList.next;
        }

        return reversedListHead;
    }

    public ListNode reverseListV2(ListNode head) {
        ListNode prev = null;
        ListNode current = head;

        while (current != null) {
            ListNode next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
}
