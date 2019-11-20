/*
 * @lc app=leetcode id=33 lang=golang
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.93%)
 * Total Accepted:    518.6K
 * Total Submissions: 1.6M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
func search(nums []int, target int) int {
	l, r := 0, len(nums)-1
	if r < 0 {
		return -1
	}
	//       /|
	//      / |
	//     /  |
	//    /   |
	//   /    |
	//  /     |
	// -------|----
	//        |  /
	//        | /
	//        |/
	for l <= r {
		mid := l + (r-l)/2
		if nums[l] == target {
			return l
		}
		if nums[r] == target {
			return r
		}
		if nums[mid] == target {
			return mid
		} else if nums[mid] > nums[l] {
			// mid 在左上
			if target > nums[l] && target < nums[mid] {
				r = mid - 1
			} else {
				l = mid + 1
			}
		} else {
			// mid 在右下
			if target > nums[mid] && target < nums[r] {
				l = mid + 1
			} else {
				r = mid - 1
			}
		}
	}
	return -1
}
