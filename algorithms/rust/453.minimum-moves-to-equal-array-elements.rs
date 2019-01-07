/*
 * @lc app=leetcode id=453 lang=rust
 *
 * [453] Minimum Moves to Equal Array Elements
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
 *
 * algorithms
 * Easy (48.74%)
 * Total Accepted:    51.8K
 * Total Submissions: 106.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array of size n, find the minimum number of moves
 * required to make all array elements equal, where a move is incrementing n -
 * 1 elements by 1.
 * 
 * Example:
 * 
 * Input:
 * [1,2,3]
 * 
 * Output:
 * 3
 * 
 * Explanation:
 * Only three moves are needed (remember each move increments two elements):
 * 
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
 * 
 */
use std::i64::MAX;

/*
已知：数列nums，初始和sum，长度len，最小的数为min
假设移动k步
每移动一步，len-1个数会被＋1，则最终和s = sum +(len-1) x k
最后结果，即每个元素的值都是 s/len
最小数每次移动都被+1，因此有：s/len = min + k
即：（sum +(len-1) x k）/len = min + k 
求得： k = sum - min x len
*/
impl Solution {
    pub fn min_moves(nums: Vec<i32>) -> i32 {
        let len = nums.len() as i64;
        let mut sum = 0i64;
        let mut min = MAX;
        for &n in nums.iter() {
            let _n = n as i64;
            if _n < min {
                min = _n;
            }
            sum += _n;
        }

        return (sum - min * len) as i32;
    }
}
