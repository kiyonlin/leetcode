/*
 * @lc app=leetcode id=448 lang=rust
 *
 * [448] Find All Numbers Disappeared in an Array
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (52.18%)
 * Total Accepted:    126K
 * Total Submissions: 241.6K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some
 * elements appear twice and others appear once.
 * 
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * 
 * Could you do it without extra space and in O(n) runtime? You may assume the
 * returned list does not count as extra space.
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [5,6]
 * 
 * 
 */

impl Solution {
    pub fn find_disappeared_numbers(nums: Vec<i32>) -> Vec<i32> {
        // [4,3,2,7,8,2,3,1]
        let mut nums = nums;
        // 出现过的数字，将其下标对应的数置为负数
        for n in 0..nums.len() {
            let i = (nums[n].abs() - 1) as usize;
            nums[i] = -nums[i].abs();
        }

        // println!("{:?}", nums);
        // debug: [-4, -3, -2, -7, 8, 2, -3, -1]
        // 只要遍历一遍，找出非负数即可

        let mut ret = vec![];
        for (i, &n) in nums.iter().enumerate() {
            if n > 0 {
                ret.push((i + 1) as i32);
            }
        }
        return ret;
    }
}
