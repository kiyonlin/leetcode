/*
 * @lc app=leetcode id=5 lang=golang
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.38%)
 * Total Accepted:    716.5K
 * Total Submissions: 2.5M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
func longestPalindrome(s string) string {
	if len(s) <= 1 {
		return s
	}
	start, maxLength := 0, 1
	for i := 0; i < len(s)-maxLength/2; i++ {
		newStart, newLength := extendPalindrome(s, i, i)
		if newLength > maxLength {
			maxLength = newLength
			start = newStart
		}
		newStart, newLength = extendPalindrome(s, i, i+1)
		if newLength > maxLength {
			maxLength = newLength
			start = newStart
		}
	}
	return s[start : start+maxLength]
}

func extendPalindrome(s string, i, j int) (int, int) {
	for i >= 0 && j < len(s) && s[i] == s[j] {
		i--
		j++
	}
	return i + 1, j - i - 1
}

