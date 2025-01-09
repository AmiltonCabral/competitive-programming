package main

// Definition for a Node.
type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

// Current: Time: O(n); Space: O(n)
// Optimal: Time: O(n); Space: O(1)
func copyRandomList(head *Node) *Node {
	copy := make(map[*Node]*Node)

	curr := head
	for curr != nil {
		node := &Node{
			Val: curr.Val,
		}
		copy[curr] = node
		curr = curr.Next
	}

	curr = head
	for curr != nil {
		node := copy[curr]
		node.Next = copy[curr.Next]
		node.Random = copy[curr.Random]
		curr = curr.Next
	}

	return copy[head]
}

var _ = copyRandomList(nil)
