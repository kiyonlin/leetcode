#
# [404] Sum of Left Leaves
#
# https://leetcode.com/problems/sum-of-left-leaves/description/
#
# algorithms
# Easy (47.82%)
# Total Accepted:    94.9K
# Total Submissions: 198.5K
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# Find the sum of all left leaves in a given binary tree.
#
# Example:
#
# ⁠   3
# ⁠  / \
# ⁠ 9  20
# ⁠   /  \
# ⁠  15   7
#
# There are two left leaves in the binary tree, with values 9 and 15
# respectively. Return 24.
#
#
#
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
total = 0


class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        total = 0
        if not root:
            return 0
        if root.left and not root.left.left and not root.left.right:
            total += root.left.val
        total += self.sumOfLeftLeaves(root.left) + \
            self.sumOfLeftLeaves(root.right)
        return total
