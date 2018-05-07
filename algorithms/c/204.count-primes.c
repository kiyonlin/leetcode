/*
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (26.52%)
 * Total Accepted:    155.7K
 * Total Submissions: 587.2K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */
int countPrimes(int n)
{
    int* table = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        table[i] = 1;
    int limit = (int)sqrt(n);
    table[0] = table[1] = 0;
    for (int i = 2; i <= limit; i++) {
        if (table[i]) {
            // 将质数的倍数标记为非质数
            for (int j = i * i; j < n; j += i)
                table[j] = 0;
        }
    }
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (table[i])
            count++;
    }
    return count;
}
