/*
 * [673] Number of Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (31.76%)
 * Total Accepted:    15.7K
 * Total Submissions: 49.4K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 
 * Given an unsorted array of integers, find the number of longest increasing
 * subsequence.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1,
 * 3, 5, 7].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of longest continuous increasing subsequence is 1,
 * and there are 5 subsequences' length is 1, so output 5.
 * 
 * 
 * 
 * Note:
 * Length of the given array will be not exceed 2000 and the answer is
 * guaranteed to be fit in 32-bit signed int.
 * 
 */
// Segment tree

// public int findNumberOfLIS(int[] nums) {
//         if (nums.length == 0) return 0;
//         int min = nums[0], max = nums[0];
//         for (int num: nums) {
//             min = Math.min(min, num);
//             max = Math.max(max, num);
//         }
//         Node root = new Node(min, max);
//         for (int num: nums) {
//             Value v = query(root, num-1);
//             insert(root, num, new Value(v.length + 1, v.count));
//         }
//         return root.val.count;
//     }
struct value {
    int len;
    int count;
};
struct node {
    int range_left, range_right;
    struct value val;
    struct node *left, *right;
};
struct node* makeNode(int start, int end)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->range_left = start, n->range_right = end;
    n->left = n->right = NULL;
    struct value v = { 0, 1 };
    n->val = v;
    return n;
}
struct value merge(struct value v1, struct value v2)
{
    if (v1.len == v2.len) {
        if (v1.len == 0) {
            struct value v = { 0, 1 };
            return v;
        }
        struct value v = { v1.len, v1.count + v2.count };
        return v;
    }
    return v1.len > v2.len ? v1 : v2;
}
struct node* getLeft(struct node* root)
{
    if (root->left == NULL)
        root->left = makeNode(root->range_left, root->range_left + (root->range_left + root->range_right) / 2);
    return root->left;
}
struct node* getRight(struct node* root)
{
    if (root->right == NULL)
        root->right = makeNode(root->range_left + (root->range_left + root->range_right) / 2 + 1, root->range_right);
    return root->right;
}
struct value query(struct node* root, int key)
{
    if (root->range_right <= key)
        return root->val;
    else if (root->range_left > key) {
        struct value v = { 0, 1 };
        return v;
    } else
        return merge(query(getLeft(root), key), query(getRight(root), key));
}

int getRangeMid(struct node* root)
{
    return root->range_left + (root->range_left + root->range_right) / 2;
}

void insert(struct node* root, int key, struct value v)
{
    if (root->range_left == root->range_right) {
        root->val = merge(v, root->val);
        return;
    } else if (key <= getRangeMid(root)) {
        insert(getLeft(root), key, v);
    } else {
        insert(getRight(root), key, v);
    }
}

int findNumberOfLIS(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    int min = nums[0], max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        min = min < nums[i] ? min : nums[i];
        max = max > nums[i] ? max : nums[i];
    }
    struct node* root = makeNode(min, max);
    for (int i = 0; i < numsSize; i++) {
        struct value v = query(root, nums[i] - 1);
        struct value newV = { v.len + 1, v.count + 1 };
        insert(root, nums[i], newV);
    }
    return root->val.count;
}

// DP n^2
// int findNumberOfLIS(int* nums, int numsSize)
// {
//     int* len = (int*)malloc(numsSize * sizeof(int));
//     int* cnt = (int*)malloc(numsSize * sizeof(int));
//     int result = 0, maxLen = 0;
//     for (int i = 0; i < numsSize; i++) {
//         len[i] = cnt[i] = 1;
//         for (int j = 0; j < i; j++)
//             if (nums[i] > nums[j]) {
//                 if (len[i] == len[j] + 1)
//                     cnt[i] += cnt[j];
//                 if (len[i] < len[j] + 1) {
//                     len[i] = len[j] + 1;
//                     cnt[i] = cnt[j];
//                 }
//             }

//         if (maxLen == len[i])
//             result += cnt[i];
//         if (maxLen < len[i]) {
//             maxLen = len[i];
//             result = cnt[i];
//         }
//     }
//     return result;
// }
