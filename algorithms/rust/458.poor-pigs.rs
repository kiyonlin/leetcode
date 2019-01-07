/*
 * @lc app=leetcode id=458 lang=rust
 *
 * [458] Poor Pigs
 *
 * https://leetcode.com/problems/poor-pigs/description/
 *
 * algorithms
 * Easy (44.37%)
 * Total Accepted:    14K
 * Total Submissions: 31.5K
 * Testcase Example:  '1000\n15\n60'
 *
 * There are 1000 buckets, one and only one of them contains poison, the rest
 * are filled with water. They all look the same. If a pig drinks that poison
 * it will die within 15 minutes. What is the minimum amount of pigs you need
 * to figure out which bucket contains the poison within one hour.
 * 
 * Answer this question, and write an algorithm for the follow-up general
 * case.
 * 
 * Follow-up: 
 * 
 * If there are n buckets and a pig drinking poison will die within m minutes,
 * how many pigs (x) you need to figure out the "poison" bucket within p
 * minutes? There is exact one bucket with poison.
 * 
 */
impl Solution {
    pub fn poor_pigs(buckets: i32, minutes_to_die: i32, minutes_to_test: i32) -> i32 {
        let test_round = minutes_to_test / minutes_to_die;
        let mut pigs = 0;
        while (test_round + 1).pow(pigs) < buckets {
            pigs += 1;
        }
        return pigs as i32;
    }
}
