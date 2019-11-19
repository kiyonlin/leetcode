/*
 * @lc app=leetcode id=15 lang=golang
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.10%)
 * Total Accepted:    701.3K
 * Total Submissions: 2.8M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
// threeSum
// 167 https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// 167的扩展，思路为设定一个目标值，在数组中找到两个数的和为目标值
func threeSum(nums []int) [][]int {
	// 先排序
	sort.Ints(nums)
	//log.Println(nums)
	length := len(nums)
	ret := [][]int{}
	for i := 0; i < length-1; i++ {
		// 若遍历到正数，则结束
		// 因为可能有三个正数和为0
		if nums[i] > 0 {
			break
		}
		// 与前一个数相同时，则继续
		// 因为不需要相同解法
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		j, k := i+1, length-1
		for j < k {
			sum := nums[i] + nums[j] + nums[k]
			if sum < 0 {
				// 和太小，增加左侧范围
				j++
			} else if sum > 0 {
				// 和太大，减小右侧范围
				k--
			} else {
				ret = append(ret, []int{nums[i], nums[j], nums[k]})
				// 两边都缩小范围，去掉重复解
				// 测试用例 -1 0 0 1 1
				//log.Println(j, k, nums[j], nums[k], target)
				for j++; j < k && nums[j-1] == nums[j]; j++ {
				}
				for k--; k > j && nums[k] == nums[k+1]; k-- {
				}
			}
		}
	}
	return ret
}
