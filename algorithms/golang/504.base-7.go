/*
 * @lc app=leetcode id=504 lang=golang
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (44.97%)
 * Total Accepted:    47.1K
 * Total Submissions: 103.9K
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 * 
 * Example 1:
 * 
 * Input: 100
 * Output: "202"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -7
 * Output: "-10"
 * 
 * 
 * 
 * Note:
 * The input will be in range of [-1e7, 1e7].
 * 
 */
func convertToBase7(num int) string {
	return strconv.FormatInt(int64(num), 7)
}
