#
# [437] Path Sum III
#
# https://leetcode.com/problems/path-sum-iii/description/
#
# algorithms
# Easy (40.29%)
# Total Accepted:    65.7K
# Total Submissions: 163.1K
# Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
#
# You are given a binary tree in which each node contains an integer value.
#
# Find the number of paths that sum to a given value.
#
# The path does not need to start or end at the root or a leaf, but it must go
# downwards
# (traveling only from parent nodes to child nodes).
#
# The tree has no more than 1,000 nodes and the values are in the range
# -1,000,000 to 1,000,000.
#
# Example:
#
# root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
#
# ⁠     10
# ⁠    /  \
# ⁠   5   -3
# ⁠  / \    \
# ⁠ 3   2   11
# ⁠/ \   \
# 3  -2   1
#
# Return 3. The paths that sum to 8 are:
#
# 1.  5 -> 3
# 2.  5 -> 2 -> 1
# 3. -3 -> 11
#
#
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def pathSum(self, root, target):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        self.result = 0
        cache = {0: 1}

        self.dfs(root, target, 0, cache)

        return self.result

    def dfs(self, root, target, currPathSum, cache):
        if root:
            currPathSum += root.val
            oldPathSum = currPathSum - target

            self.result += cache.get(oldPathSum, 0)
            cache[currPathSum] = cache.get(currPathSum, 0) + 1

            self.dfs(root.left, target, currPathSum, cache)
            self.dfs(root.right, target, currPathSum, cache)

            cache[currPathSum] -= 1
