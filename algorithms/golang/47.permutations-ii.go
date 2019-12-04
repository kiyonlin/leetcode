/*
 * @lc app=leetcode id=47 lang=golang
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (40.69%)
 * Total Accepted:    291.7K
 * Total Submissions: 675.2K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
func permuteUnique(nums []int) [][]int {
	ret := make([][]int, 0)
	var backtrace func(int)
	backtrace = func(start int) {
		if start == len(nums)-1 {
			ans := make([]int, len(nums))
			copy(ans, nums)
			ret = append(ret, ans)
			return
		}
		visited := make(map[int]bool)
		for i := start; i < len(nums); i++ {
			// 当前位置的值只重复一次
			if _, ok := visited[nums[i]]; !ok {
				visited[nums[i]] = true
				nums[i], nums[start] = nums[start], nums[i]
				backtrace(start + 1)
				nums[i], nums[start] = nums[start], nums[i]
			}
		}
	}

	backtrace(0)

	return ret
}
