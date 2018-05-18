/*
 * [646] Maximum Length of Pair Chain
 *
 * https://leetcode.com/problems/maximum-length-of-pair-chain/description/
 *
 * algorithms
 * Medium (47.35%)
 * Total Accepted:    19.7K
 * Total Submissions: 41.5K
 * Testcase Example:  '[[1,2], [2,3], [3,4]]'
 *
 * 
 * You are given n pairs of numbers. In every pair, the first number is always
 * smaller than the second number.
 * 
 * 
 * 
 * Now, we define a pair (c, d) can follow another pair (a, b) if and only if b
 * < c. Chain of pairs can be formed in this fashion. 
 * 
 * 
 * 
 * Given a set of pairs, find the length longest chain which can be formed. You
 * needn't use up all the given pairs. You can select pairs in any order.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [[1,2], [2,3], [3,4]]
 * Output: 2
 * Explanation: The longest chain is [1,2] -> [3,4]
 * 
 * 
 * 
 * Note:
 * 
 * The number of given pairs will be in the range [1, 1000].
 * 
 * 
 */
int cmp(void** aa, void** bb)
{
    int* a = *(int**)aa;
    int* b = *(int**)bb;
    return a[1] - b[1];
}
int findLongestChain(int** pairs, int pairsRowSize, int pairsColSize)
{
    qsort(pairs, pairsRowSize, sizeof(int*), cmp);
    int cur = INT_MIN, result = 0;
    for (int i = 0; i < pairsRowSize; i++)
        if (cur < pairs[i][0]) {
            cur = pairs[i][1];
            result++;
        }
    return result;
}
