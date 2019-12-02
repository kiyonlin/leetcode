/*
 * @lc app=leetcode id=39 lang=golang
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (48.80%)
 * Total Accepted:    427.3K
 * Total Submissions: 822.5K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
func combinationSum(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	ret := make([][]int, 0)
	ans := make([]int, 0)
	backtrack(candidates, target, 0, &ans, &ret)
	return ret
}

func backtrack(nums []int, target, i int, ans *[]int, ret *[][]int) {
	if target < 0 {
		return
	}
	if target == 0 {
		*ret = append(*ret, append(make([]int, 0), (*ans)...))
		return
	}
	for j := i; j < len(nums) && target >= nums[j]; j++ {
		*ans = append(*ans, nums[j])
		backtrack(nums, target-nums[j], j, ans, ret)
		*ans = (*ans)[:len(*ans)-1]
	}
}
