/*
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (42.81%)
 * Total Accepted:    239.2K
 * Total Submissions: 558.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
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
 * return its level order traversal as:
 *
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
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
func traversal(root *TreeNode, depth int, result *[][]int) {
	if root == nil {
		return
	}
	if len(*result) == depth {
		*result = append(*result, []int{})
	}
	(*result)[depth] = append((*result)[depth], root.Val)
	traversal(root.Left, depth+1, result)
	traversal(root.Right, depth+1, result)
}

func levelOrder(root *TreeNode) [][]int {
	var result = [][]int{}
	traversal(root, 0, &result)
	return result
}
