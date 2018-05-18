/*
 * [650] 2 Keys Keyboard
 *
 * https://leetcode.com/problems/2-keys-keyboard/description/
 *
 * algorithms
 * Medium (45.05%)
 * Total Accepted:    19K
 * Total Submissions: 42.2K
 * Testcase Example:  '3'
 *
 * 
 * Initially on a notepad only one character 'A' is present. You can perform
 * two operations on this notepad for each step: 
 * 
 * Copy All: You can copy all the characters present on the notepad (partial
 * copy is not allowed).
 * Paste: You can paste the characters which are copied last time.
 * 
 * 
 * 
 * 
 * Given a number n. You have to get exactly n 'A' on the notepad by performing
 * the minimum number of steps permitted. Output the minimum number of steps to
 * get n 'A'. 
 * 
 * 
 * Example 1:
 * 
 * Input: 3
 * Output: 3
 * Explanation:
 * Intitally, we have one character 'A'.
 * In step 1, we use Copy All operation.
 * In step 2, we use Paste operation to get 'AA'.
 * In step 3, we use Paste operation to get 'AAA'.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The n will be in the range [1, 1000].
 * 
 * 
 */

int minSteps(int n)
{
    int result = 0, d = 2;
    while (n > 1) {
        while (n % d == 0) {
            result += d;
            n /= d;
        }
        d++;
    }
    return result;
}

// DP
// inline int MIN(int a, int b) { return a < b ? a : b; }
// int minSteps(int n)
// {
//     int* dp = (int*)malloc((n + 1) * sizeof(int));
//     dp[1] = 0;
//     for (int i = 2; i <= n; i++) {
//         dp[i] = i;
//         for (int j = i - 1; j > 1; j--)
//             if (i % j == 0)
//                 dp[i] = MIN(dp[i], dp[j] + i / j);
//     }

//     // for (int i = 2; i <= n; i++) {
//     //     dp[i] = i;
//     //     for (int j = i - 1; j > 1; j--)
//     //         if (i % j == 0) {
//     //             dp[i] = dp[j] + i / j;
//     //             break;
//     //         }
//     // }

//     return dp[n];
// }
