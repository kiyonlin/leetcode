/*
 * @lc app=leetcode id=29 lang=golang
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.15%)
 * Total Accepted:    228.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 231 − 1 when the division
 * result overflows.
 * 
 * 
 */
func divide(dividend int, divisor int) int {
	quotient, _ := div(dividend, divisor)
	if quotient > (1<<31 - 1) {
		quotient = 1<<31 - 1
	}
	return quotient
}

// 参考资料 https://www.jianshu.com/p/7bba031b11e7
func add(sum, carry int) int {
	for carry != 0 {
		tmp := sum
		sum ^= carry
		carry = (tmp & carry) << 1
	}
	return sum
}

func sub(a, b int) int {
	return add(a, add(^b, 1))
}

func multi(a, b int) int {
	// 将被乘数和乘数转为绝对值
	multiplicand := a
	if multiplicand < 0 {
		multiplicand = add(^a, 1)
	}
	multiplier := b
	if multiplier < 0 {
		multiplier = add(^b, 1)
	}
	product := 0
	for multiplier > 0 {
		if multiplier&0x1 > 0 {
			product = add(product, multiplicand)
		}
		multiplier >>= 1
		multiplicand <<= 1
	}
	// 确定符号
	if a^b < 0 {
		product = add(^product, 1)
	}

	return product
}

func div(a, b int) (int, int) {
	// 将被除数和除数转为绝对值
	dividend := a
	if dividend < 0 {
		dividend = add(^a, 1)
	}
	divisor := b
	if divisor < 0 {
		divisor = add(^b, 1)
	}
	remainder := dividend
	quotient := 0
	// 暴力减除数
	//for remainder >= divisor {
	//	remainder = sub(remainder, divisor)
	//	quotient = add(quotient, 1)
	//}
	// 依次减2的次方
	for i := 31; i >= 0; i-- {
		if (remainder >> uint(i)) >= divisor {
			quotient = add(quotient, 1<<uint(i))
			remainder = sub(remainder, divisor<<uint(i))
		}
	}

	if a^b < 0 {
		quotient = add(^quotient, 1)
	}
	if b < 0 {
		remainder = add(^remainder, 1)
	}

	return quotient, remainder
}
