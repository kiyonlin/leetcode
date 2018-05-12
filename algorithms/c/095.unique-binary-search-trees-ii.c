/*
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (32.40%)
 * Total Accepted:    102.3K
 * Total Submissions: 315.9K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct TreeNode* makeNode(int);
struct TreeNode* clone(struct TreeNode*);
void printTree(struct TreeNode*);
void freeTemp(struct TreeNode**, int);
int cmp(void** aa, void** bb)
{
    struct TreeNode* a = *(struct TreeNode**)aa;
    struct TreeNode* b = *(struct TreeNode**)bb;
    return a->val - b->val;
}
struct TreeNode** generateTrees(int n, int* returnSize)
{
    if (n == 0)
        return NULL;

    *returnSize = 1;
    struct TreeNode** result = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    result[0] = makeNode(1);

    for (int i = 2; i <= n; i++) {
        struct TreeNode** temp = NULL;
        int k = 0;
        for (int j = 0; j < *returnSize; j++) {
            struct TreeNode* oldBST = result[j];

            if (oldBST != NULL) {
                struct TreeNode* node2 = oldBST;
                while (node2->right != NULL)
                    node2 = node2->right;
                node2->right = makeNode(i);
                temp = (struct TreeNode**)realloc(temp, sizeof(struct TreeNode*) * (++k));
                temp[k - 1] = clone(oldBST);
                node2->right = NULL;

                struct TreeNode* node = oldBST;
                while (node->right != NULL) {
                    struct TreeNode* newNode = makeNode(i);
                    struct TreeNode* tempRight = node->right;
                    // 构造新节点的左树
                    node->right = newNode;
                    newNode->left = tempRight;
                    temp = (struct TreeNode**)realloc(temp, sizeof(struct TreeNode*) * (++k));
                    temp[k - 1] = clone(oldBST);

                    node->right = tempRight;
                    node = node->right;
                }
            }

            // 新的根节点，老树作为左节点
            struct TreeNode* newBST = makeNode(i);
            newBST->left = clone(oldBST);

            temp = (struct TreeNode**)realloc(temp, sizeof(struct TreeNode*) * (++k));
            temp[k - 1] = newBST;
        }
        freeTemp(result, *returnSize);
        // 更新result
        *returnSize = k;
        result = temp;
    }
    qsort(result, *returnSize, sizeof(struct TreeNode*), cmp);
    return result;
}

void freeTree(struct TreeNode* root)
{
    if (!root)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void freeTemp(struct TreeNode** tree, int n)
{
    for (int i = 0; i < n; i++)
        freeTree(tree[i]);
}

void printTree(struct TreeNode* root)
{
    if (!root)
        return;
    printTree(root->left);
    printf("%d", root->val);
    printTree(root->right);
}
struct TreeNode* makeNode(int val)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* clone(struct TreeNode* root)
{
    if (!root)
        return NULL;
    struct TreeNode* newRoot = makeNode(root->val);
    newRoot->left = clone(root->left);
    newRoot->right = clone(root->right);
    return newRoot;
}