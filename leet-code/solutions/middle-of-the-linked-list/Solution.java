package middleofthelinkedlist;

class Solution {
    public ListNode middleNode(ListNode head) {
        if (head == null)
            return null;

        int length = 1;
        int middle;
        ListNode currentNode = head.next;

        while (currentNode != null) {
            currentNode = currentNode.next;
            length++;
        }

        middle = (int) length / 2;

        for (int i = 0; i < middle; i++) {
            head = head.next;
        }

        return head;
    }

    public ListNode middleNodeV2(ListNode head) {
        if (head == null)
            return null;

        int length = 1;
        int middle;
        ListNode node = head;

        while (head.next != null) {
            head = head.next;
            length++;
        }

        middle = (int) length / 2;

        for (int i = 0; i < middle; i++) {
            node = node.next;
        }

        return node;
    }
}
