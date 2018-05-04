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
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int depth(struct TreeNode* root)
{
    int left, right, max;
    if (root) {
        left = depth(root->left);
        right = depth(root->right);
        max = left > right ? left : right;
        return max + 1;
    }
    return 0;
}

int** traversal(struct TreeNode* root, int** columnSizes, int* returnSize, int depth, int*** result)
{
    if (!root)
        return;
    traversal(root->left, columnSizes, returnSize, depth + 1, result);
    traversal(root->right, columnSizes, returnSize, depth + 1, result);
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    int** result;
    result = NULL;

    // 获取🌲的深度
    *returnSize = depth(root);
    // 根据深度输出 左-右-中
    traversal(root, columnSizes, returnSize, 1, &result);

    return result;
}
