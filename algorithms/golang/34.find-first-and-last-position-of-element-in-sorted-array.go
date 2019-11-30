/*
 * @lc app=leetcode id=34 lang=golang
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (33.64%)
 * Total Accepted:    383K
 * Total Submissions: 1.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
func searchRange(nums []int, target int) []int {
	l, r := 0, len(nums)
	for l < r {
		mid := (l + r) >> 1
		if nums[mid] < target {
			l = mid + 1
		} else {
			r = mid
		}
	}

	first := l
	// 未找到目标
	if first == len(nums) || nums[first] != target {
		return []int{-1, -1}
	}

	// 找上界
	l, r = 0, len(nums)
	for l < r {
		mid := (l + r) >> 1
		if nums[mid] <= target {
			l = mid + 1
		} else {
			r = mid
		}
	}
	return []int{first, l - 1}
}
