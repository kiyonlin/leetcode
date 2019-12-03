/*
 * @lc app=leetcode id=43 lang=golang
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (30.80%)
 * Total Accepted:    241.6K
 * Total Submissions: 752.2K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
func multiply(num1 string, num2 string) string {
	l1, l2 := len(num1), len(num2)
	ret := make([]byte, l1+l2, l1+l2)
	for i := l1 - 1; i >= 0; i-- {
		for j := l2 - 1; j >= 0; j-- {
			k := i + j + 1
			ret[k] += byte((num1[i] - '0') * (num2[j] - '0'))
			if ret[k] >= 10 {
				ret[k-1] += ret[k] / 10
				ret[k] %= 10
			}
		}
	}

	// 去掉前导0
	start := 0
	for ; start < len(ret) && ret[start] == 0; start++ {
	}
	if start == len(ret) {
		return "0"
	}

	for i := start; i < len(ret); i++ {
		ret[i] += '0'
	}
	return string(ret[start:])
}
