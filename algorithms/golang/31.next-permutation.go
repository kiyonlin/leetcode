/*
 * @lc app=leetcode id=31 lang=golang
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (30.55%)
 * Total Accepted:    291.6K
 * Total Submissions: 929.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
func nextPermutation(nums []int) {
	l := len(nums)
	if l <= 1 {
		return
	}
	i := l - 2
	// 先找到第一个非降序序列的位置
	for ; i >= 0 && nums[i] >= nums[i+1]; i-- {
	}
	if i >= 0 {
		// 从后往前找，找到第一个大于非降序位置的值
		j := l - 1
		for ; j > i && nums[j] <= nums[i]; j-- {
		}
		// 换一个大一点的数上来
		swap(nums, i, j)
	}
	// 最后反序一下
	reverse(nums, i+1, l-1)
}

func swap(nums []int, i, j int) {
	nums[i] ^= nums[j]
	nums[j] ^= nums[i]
	nums[i] ^= nums[j]
}

func reverse(nums []int, i, j int) {
	for i < j {
		swap(nums, i, j)
		i, j = i+1, j-1
	}
}
