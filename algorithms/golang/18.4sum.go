/*
 * @lc app=leetcode id=18 lang=golang
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (30.65%)
 * Total Accepted:    276.1K
 * Total Submissions: 865.8K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
func fourSum(nums []int, target int) [][]int {
	length := len(nums)
	// 先排序
	sort.Ints(nums)
	log.Println(nums)
	ret := [][]int{}
	for i := 0; i < length-3; i++ {
		if nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target {
			break
		}
		if nums[i]+nums[length-1]+nums[length-2]+nums[length-3] < target {
			continue
		}
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j := i + 1; j < length-2; j++ {
			if nums[i]+nums[j]+nums[i+2]+nums[i+3] > target {
				break
			}
			if nums[i]+nums[j]+nums[length-1]+nums[length-2] < target {
				continue
			}
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}
			l, r := j+1, length-1
			for l < r {
				sum := nums[i] + nums[j] + nums[l] + nums[r]
				if sum < target {
					l++
				} else if sum > target {
					r--
				} else {
					ret = append(ret, []int{nums[i], nums[j], nums[l], nums[r]})
					for l++; l < r && nums[l] == nums[l-1]; l++ {
					}
					for r--; l < r && nums[r] == nums[r+1]; r-- {
					}
				}
			}
		}
	}
	return ret
}
