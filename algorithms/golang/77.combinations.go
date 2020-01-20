/*
 * @lc app=leetcode id=77 lang=golang
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (47.90%)
 * Total Accepted:    242.1K
 * Total Submissions: 475.1K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
func combine(n int, k int) [][]int {
	ret := make([][]int, 0)
	comb := make([]int, k, k)

	var dfs func(int, int)
	dfs = func(ind, start int) {
		if ind == k {
			cp := make([]int, k, k)
			copy(cp, comb)
			ret = append(ret, cp)
			return
		}

		for i := start; i <= n-(k-1)+ind; i++ {
			comb[ind] = i
			dfs(ind+1, i+1)
		}
	}

	dfs(0, 1)

	return ret
}
