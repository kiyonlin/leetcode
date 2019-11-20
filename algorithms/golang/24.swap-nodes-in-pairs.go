/*
 * @lc app=leetcode id=24 lang=golang
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (44.90%)
 * Total Accepted:    377K
 * Total Submissions: 799.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
	//printList(head)
	cur, pre := head, &ListNode{}
	changeHead := false
	for cur != nil && cur.Next != nil {
		next := cur.Next
		cur.Next = next.Next
		next.Next = cur
		pre.Next = next

		pre = cur
		cur = cur.Next

		if !changeHead {
			changeHead = true
			head = next
		}
	}
	//printList(head)
	return head
}

func printList(head *ListNode) {
	for head != nil {
		print(head.Val, "->")
		head = head.Next
	}
	print("nil\n")
}
