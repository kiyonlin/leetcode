/*
 * @lc app=leetcode id=75 lang=golang
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (42.31%)
 * Total Accepted:    383.1K
 * Total Submissions: 872K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 * 
 * 
 */
func sortColors(nums []int) {
	zero, one, two := -1, 0, len(nums)
	for one < two {
		switch nums[one] {
		case 1:
			one++
		case 2:
			two--
			// two的位置不为2时，进行交换
			if nums[two] != 2 {
				nums[two], nums[one] = nums[one], nums[two]
			}
		case 0:
			zero++
			nums[zero], nums[one] = nums[one], nums[zero]
			one++
		}
	}
}
