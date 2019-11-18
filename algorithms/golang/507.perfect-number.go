/*
 * @lc app=leetcode id=507 lang=golang
 *
 * [507] Perfect Number
 *
 * https://leetcode.com/problems/perfect-number/description/
 *
 * algorithms
 * Easy (34.38%)
 * Total Accepted:    50.1K
 * Total Submissions: 143.1K
 * Testcase Example:  '28'
 *
 * We define the Perfect Number is a positive integer that is equal to the sum
 * of all its positive divisors except itself. 
 * 
 * Now, given an integer n, write a function that returns true when it is a
 * perfect number and false when it is not.
 * 
 * 
 * Example:
 * 
 * Input: 28
 * Output: True
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 * 
 * 
 * 
 * Note:
 * The input number n will not exceed 100,000,000. (1e8)
 * 
 */
func checkPerfectNumber(num int) bool {
	if num == 1 {
		return false
	}
	target := num - 1
	for i := 2; i <= int(math.Sqrt(float64(num))); i++ {
		if num/i*i == num {
			target -= i
			target -= num / i
			if target < 0 {
				break
			}
		}
	}
	return target == 0
}
