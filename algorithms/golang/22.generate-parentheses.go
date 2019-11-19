/*
 * @lc app=leetcode id=22 lang=golang
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (55.20%)
 * Total Accepted:    423K
 * Total Submissions: 727.6K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
func generateParenthesis(n int) []string {
	ret := []string{}
	generateParenthesisDFS(n, n, "", &ret)
	return ret
}

func generateParenthesisDFS(l, r int, buf string, ret *[]string) {
	if l == 0 && r == 0 {
		*ret = append(*ret, string(buf))
		return
	}
	if l > 0 {
		generateParenthesisDFS(l-1, r, buf+"(", ret)
	}
	if r > 0 && l < r {
		generateParenthesisDFS(l, r-1, buf+")", ret)
	}
}
