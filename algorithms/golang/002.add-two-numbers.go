/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (28.68%)
 * Total Accepted:    485.9K
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 *
 * Example
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var result, cur *ListNode = new(ListNode), nil
	hold := 0
	for l1 != nil || l2 != nil || hold != 0 {
		if cur == nil {
			cur = result
		} else {
			cur.Next = new(ListNode)
			cur = cur.Next
		}

		cur.Val += hold

		if l1 != nil {
			cur.Val += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			cur.Val += l2.Val
			l2 = l2.Next
		}
		hold = cur.Val / 10
		cur.Val %= 10
	}
	return result
}
