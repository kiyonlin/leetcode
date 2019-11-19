/*
 * @lc app=leetcode id=16 lang=golang
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.77%)
 * Total Accepted:    398.3K
 * Total Submissions: 871.5K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
func threeSumClosest(nums []int, target int) int {
	length := len(nums)
	// 先排序
	sort.Ints(nums)
	minSum, minDist := 0, math.MaxInt32
	for i := 0; i < length-1; i++ {
		j, k := i+1, length-1
		for j < k {
			sum := nums[i] + nums[j] + nums[k]
			dist := abs(sum - target)
			if dist < minDist {
				minSum, minDist = sum, dist
			}
			if sum < target {
				j++
			} else if sum > target {
				k--
			} else {
				return target
			}
		}
	}
	return minSum
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
