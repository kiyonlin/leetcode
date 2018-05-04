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
int** traversal(struct TreeNode* root, int** columnSizes, int* returnSize, int depth, int*** result)
{
    if (!root)
        return;

    // 到达了新的深度
    if (*returnSize < depth + 1) {
        *returnSize = depth + 1;

        // 初始化
        (*result) = realloc((*result), (depth + 1) * sizeof(int*));
        (*result)[depth] = NULL;

        *columnSizes = realloc(*columnSizes, (depth + 1) * sizeof(int));
        (*columnSizes)[depth] = 0;
    }

    (*result)[depth] = realloc((*result)[depth], ((*columnSizes)[depth] + 1) * sizeof(int));
    (*result)[depth][(*columnSizes)[depth]] = root->val;
    ++(*columnSizes)[depth];

    traversal(root->left, columnSizes, returnSize, depth + 1, result);
    traversal(root->right, columnSizes, returnSize, depth + 1, result);
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    int** result;
    result = NULL;
    *returnSize = 0;
    // 根据深度输出
    traversal(root, columnSizes, returnSize, 0, &result);

    return result;
}
