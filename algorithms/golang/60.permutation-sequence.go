/*
 * @lc app=leetcode id=60 lang=golang
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (33.22%)
 * Total Accepted:    157.2K
 * Total Submissions: 453.6K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the kth permutation sequence.
 * 
 * Note:
 * 
 * 
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 * 
 */

// 参考 康拓编码与解码
// https://blog.csdn.net/yuqinjh/article/details/79427400
func getPermutation(n int, k int) string {
	// 0-9的阶乘数
	t := []int{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}
	// 数字列表
	nums := []byte{'1', '2', '3', '4', '5', '6', '7', '8', '9'}
	ret := &bytes.Buffer{}
	k--
	for i := n; i >= 1; i-- {
		j := k / t[i-1]
		ret.WriteByte(nums[j])
		nums = append(nums[:j], nums[j+1:]...)
		k %= t[i-1]
	}
	return ret.String()
}

