/*
 * @lc app=leetcode id=501 lang=golang
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (39.57%)
 * Total Accepted:    67.2K
 * Total Submissions: 166.2K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * 
 * return [2].
 * 
 * Note: If a tree has more than one mode, you can return them in any order.
 * 
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
 * 
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findMode(root *TreeNode) []int {
	r := []int{}
	curVal, curCount, maxCount := 0, 0, 0
	traveled := false
	// 对排好序的列表统计每个元素的数量
	// 并记录最大值
	handleVal := func(val int) {
		if val != curVal {
			curVal = val
			curCount = 0
		}
		curCount++
		// 第一次遍历统计最大值
		if !traveled && curCount > maxCount {
			maxCount = curCount
		}
		// 第二次遍历时再比较元素数量是否和最大值一样
		if traveled && curCount == maxCount {
			r = append(r, val)
		}
	}
	var travelTree func(root *TreeNode)
	// 前序遍历二叉树，可以理解为一个排好序的列表
	travelTree = func(root *TreeNode) {
		if root == nil {
			return
		}
		travelTree(root.Left)
		handleVal(root.Val)
		travelTree(root.Right)
	}

	// 第一遍统计
	travelTree(root)
	traveled = true
	curVal, curCount = 0, 0
	// 第二遍与最大值比较
	travelTree(root)

	return r
}