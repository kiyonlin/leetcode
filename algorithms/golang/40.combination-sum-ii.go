/*
 * @lc app=leetcode id=40 lang=golang
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (41.83%)
 * Total Accepted:    266.9K
 * Total Submissions: 600.1K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
func combinationSum2(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	ret := make([][]int, 0)
	backtrack(candidates, target, 0, make([]int, 0), &ret)
	return ret
}

func backtrack(nums []int, target, i int, ans []int, ret *[][]int) {
	if target < 0 {
		return
	}
	if target == 0 {
		*ret = append(*ret, ans)
		return
	}
	for j := i; j < len(nums) && target >= nums[j]; j++ {
		// 接下来同一个位置不能使用相同的数
		if j > i && nums[j] == nums[j-1] {
			continue
		}
		ans = append(ans, nums[j])
		backtrack(nums, target-nums[j], j+1, append(make([]int, 0), ans...), ret)
		ans = ans[:len(ans)-1]
	}
}
