/*
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (42.36%)
 * Total Accepted:    164.4K
 * Total Submissions: 388.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 *
 * return its bottom-up level order traversal as:
 *
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 *
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
func getDepth(root *TreeNode) int {
	if root != nil {
		left := getDepth(root.Left)
		right := getDepth(root.Right)
		if left > right {
			return left + 1
		} else {
			return right + 1
		}
	}
	return 0
}

func traversal(root *TreeNode, depth, maxDepth int, result *[][]int) {
	if root == nil {
		return
	}
	traversal(root.Left, depth+1, maxDepth, result)
	traversal(root.Right, depth+1, maxDepth, result)

	i := maxDepth - depth - 1
	(*result)[i] = append((*result)[i], root.Val)
}

func levelOrderBottom(root *TreeNode) [][]int {
	depth := getDepth(root)
	var result = make([][]int, depth)
	traversal(root, 0, depth, &result)
	return result
}
