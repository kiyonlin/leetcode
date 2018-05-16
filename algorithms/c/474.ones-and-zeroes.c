/*
 * [474] Ones and Zeroes
 *
 * https://leetcode.com/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (38.73%)
 * Total Accepted:    20.8K
 * Total Submissions: 53.7K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * In the computer world, use restricted resource you have to generate maximum
 * benefit is what we always want to pursue.
 * For now, suppose you are a dominator of m 0s and n 1s respectively. On the
 * other hand, there is an array with strings consisting of only 0s and 1s.
 * 
 * 
 * Now your task is to find the maximum number of strings that you can form
 * with given m 0s and n 1s. Each 0 and 1 can be used at most once.
 * 
 * 
 * 
 * Note:
 * 
 * The given numbers of 0s and 1s will both not exceed 100
 * The size of given string array won't exceed 600.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 * Output: 4
 * 
 * Explanation: This are totally 4 strings can be formed by the using of 5 0s
 * and 3 1s, which are “10,”0001”,”1”,”0”
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: Array = {"10", "0", "1"}, m = 1, n = 1
 * Output: 2
 * 
 * Explanation: You could form "10", but then you'd have nothing left. Better
 * form "0" and "1".
 * 
 * 
 */
inline int MAX(int a, int b) { return a > b ? a : b; }

int findMaxForm(char** strs, int strsSize, int m, int n)
{
    int** dp = (int**)malloc(sizeof(int*) * (m + 1));
    for (int i = 0; i <= m; i++)
        dp[i] = (int*)calloc(n + 1, sizeof(int));

    int zeroes, ones, len;
    for (int k = 0; k < strsSize; k++) {
        zeroes = 0, ones = 0, len = strlen(strs[k]);
        for (int i = 0; i < len; i++)
            strs[k][i] == '0' ? zeroes++ : ones++;

        for (int i = m; i >= zeroes; i--)
            for (int j = n; j >= ones; j--)
                dp[i][j] = MAX(dp[i][j], dp[i - zeroes][j - ones] + 1);
    }

    return dp[m][n];
}
