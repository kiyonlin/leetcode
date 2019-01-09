/*
 * @lc app=leetcode id=461 lang=rust
 *
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (69.74%)
 * Total Accepted:    208K
 * Total Submissions: 298.2K
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 * 
 * Given two integers x and y, calculate the Hamming distance.
 * 
 * Note:
 * 0 ≤ x, y < 2^31.
 * 
 * 
 * Example:
 * 
 * Input: x = 1, y = 4
 * 
 * Output: 2
 * 
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 * 
 * The above arrows point to positions where the corresponding bits are
 * different.
 * 
 * 
 */
impl Solution {
    pub fn hamming_distance(x: i32, y: i32) -> i32 {
        let xor = x ^ y;
        let mut count = 0;
        for i in 0..32 {
            count += xor >> i & 1;
        }

        count
    }
}
