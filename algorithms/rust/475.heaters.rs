/*
 * @lc app=leetcode id=475 lang=rust
 *
 * [475] Heaters
 *
 * https://leetcode.com/problems/heaters/description/
 *
 * algorithms
 * Easy (30.63%)
 * Total Accepted:    40.5K
 * Total Submissions: 132.1K
 * Testcase Example:  '[1,2,3]\n[2]'
 *
 * Winter is coming! Your first job during the contest is to design a standard
 * heater with fixed warm radius to warm all the houses.
 * 
 * Now, you are given positions of houses and heaters on a horizontal line,
 * find out minimum radius of heaters so that all houses could be covered by
 * those heaters.
 * 
 * So, your input will be the positions of houses and heaters seperately, and
 * your expected output will be the minimum radius standard of heaters.
 * 
 * Note:
 * 
 * Numbers of houses and heaters you are given are non-negative and will not
 * exceed 25000.
 * Positions of houses and heaters you are given are non-negative and will not
 * exceed 10^9.
 * As long as a house is in the heaters' warm radius range, it can be warmed.
 * All the heaters follow your radius standard and the warm radius will the
 * same.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,3],[2]
 * Output: 1
 * Explanation: The only heater was placed in the position 2, and if we use the
 * radius 1 standard, then all the houses can be warmed.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4],[1,4]
 * Output: 1
 * Explanation: The two heater was placed in the position 1 and 4. We need to
 * use radius 1 standard, then all the houses can be warmed.
 * 
 * 
 */
impl Solution {
    pub fn find_radius(houses: Vec<i32>, heaters: Vec<i32>) -> i32 {
        let mut houses = houses;
        let mut heaters = heaters;
        houses.sort();
        heaters.sort();
        let mut ret = vec![std::i32::MAX; houses.len()];
        let mut i = 0;
        let mut j = 0;
        // 正向遍历，计算每个房子最近的加热器
        while i < houses.len() && j < heaters.len() {
            if houses[i] <= heaters[j] {
                ret[i] = heaters[j] - houses[i];
                i += 1;
            } else {
                j += 1;
            }
        }
        i = houses.len() - 1;
        j = heaters.len() - 1;
        // 逆向遍历，更新每个房子最近的加热器
        loop {
            if houses[i] >= heaters[j] {
                ret[i] = std::cmp::min(ret[i], houses[i] - heaters[j]);
                if i == 0 { break; } else { i -= 1; }
            } else {
                if j == 0 { break; } else { j -= 1; }
            }
        }

        *ret.iter().max().unwrap_or(&0i32)
    }
}
