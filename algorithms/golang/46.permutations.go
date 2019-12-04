/*
 * @lc app=leetcode id=46 lang=golang
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (55.47%)
 * Total Accepted:    473.4K
 * Total Submissions: 805.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
func permute(nums []int) [][]int {
	ret := make([][]int, 0)
	var backtrace func(int)
	backtrace = func(start int) {
		if start == len(nums)-1 {
			ans := make([]int, len(nums))
			copy(ans, nums)
			ret = append(ret, ans)
			return
		}
		for i := start; i < len(nums); i++ {
			nums[i], nums[start] = nums[start], nums[i]
			backtrace(start + 1)
			nums[i], nums[start] = nums[start], nums[i]
		}
	}

	backtrace(0)

	return ret
}
