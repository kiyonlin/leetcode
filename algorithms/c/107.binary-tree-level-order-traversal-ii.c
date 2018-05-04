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
void init(struct TreeNode* root, int** columnSizes, int* returnSize, int depth, int*** result)
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

    init(root->left, columnSizes, returnSize, depth + 1, result);
    init(root->right, columnSizes, returnSize, depth + 1, result);
}

void traversal(struct TreeNode* root, int** columnSizes, int* returnSize, int depth, int*** result)
{
    if (!root)
        return;
    traversal(root->left, columnSizes, returnSize, depth + 1, result);
    traversal(root->right, columnSizes, returnSize, depth + 1, result);

    int i = *returnSize - depth - 1;
    (*result)[i] = realloc((*result)[i], ((*columnSizes)[i] + 1) * sizeof(int));
    (*result)[i][(*columnSizes)[i]] = root->val;
    ++(*columnSizes)[i];
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    int** result;
    result = NULL;
    *returnSize = 0;
    // 获取树的深度
    init(root, columnSizes, returnSize, 0, &result);
    // 根据深度输出 左-右-中
    traversal(root, columnSizes, returnSize, 0, &result);

    return result;
}
