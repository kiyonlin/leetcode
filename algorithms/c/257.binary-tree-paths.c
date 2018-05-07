/*
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (41.51%)
 * Total Accepted:    159K
 * Total Submissions: 383K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * 
 * For example, given the following binary tree:
 * 
 * 
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 
 * 
 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
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
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void traversal(struct TreeNode* node, int* returnSize, char*** result, char* path)
{
    if (!node)
        return;
    char* newPath = NULL;
    if (node->left == NULL && node->right == NULL) {
        asprintf(&newPath, "%s%d", path, node->val);
        *result = realloc(*result, ++(*returnSize) * sizeof(char**));
        (*result)[*returnSize - 1] = newPath;
        return;
    }
    asprintf(&newPath, "%s%d->", path, node->val);
    traversal(node->left, returnSize, result, newPath);
    traversal(node->right, returnSize, result, newPath);
    free(newPath);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    char** result = NULL;
    traversal(root, returnSize, &result, "");
    return result;
}
