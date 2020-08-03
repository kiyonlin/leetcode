
/*
 * @lc app=leetcode id=78 lang=golang
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (53.10%)
 * Total Accepted:    467.9K
 * Total Submissions: 817.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 *
 */
func subsets(nums []int) [][]int {
	ret := make([][]int, 0)
	for i := 0; i < 1<<uint8(len(nums)); i++ {
		subset := make([]int, 0, len(nums))
		for j, k := i, 0; j > 0; j, k = j>>1, k+1 {
			// extract bitmask element
			if j&1 == 1 {
				subset = append(subset, nums[k])
			}
		}
		ret = append(ret, subset)
	}

	return ret
}
