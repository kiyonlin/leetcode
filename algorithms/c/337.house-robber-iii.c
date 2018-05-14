/*
 * [337] House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (44.86%)
 * Total Accepted:    65.6K
 * Total Submissions: 146.2K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * 
 * The thief has found himself a new place for his thievery again. There is
 * only one entrance to this area, called the "root." Besides the root, each
 * house has one and only one parent house. After a tour, the smart thief
 * realized that "all houses in this place forms a binary tree". It will
 * automatically contact the police if two directly-linked houses were broken
 * into on the same night.
 * 
 * 
 * 
 * Determine the maximum amount of money the thief can rob tonight without
 * alerting the police.
 * 
 * 
 * Example 1:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \   \ 
 * ⁠    3   1
 * 
 * Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * 
 * 
 * Example 2:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \   \ 
 * ⁠1   3   1
 * 
 * Maximum amount of money the thief can rob = 4 + 5 = 9.
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(a, b) (a) > (b) ? (a) : (b)

int* robHouse(struct TreeNode* root)
{
    // rob[0] for rob the house
    // rob[1] for not rob the house
    int* rob = (int*)calloc(2, sizeof(int));
    if (root) {
        int* robLeft = robHouse(root->left);
        int* robRight = robHouse(root->right);
        rob[0] = MAX(robLeft[1] + robRight[1] + root->val, robLeft[0] + robRight[0]);
        rob[1] = MAX(robLeft[0] + robRight[0], robLeft[1] + robRight[1]);
        free(robLeft);
        free(robRight);
    }
    return rob;
}

int rob(struct TreeNode* root)
{
    int* robRoot = robHouse(root);
    int result = MAX(robRoot[0], robRoot[1]);
    free(robRoot);
    return result;
}