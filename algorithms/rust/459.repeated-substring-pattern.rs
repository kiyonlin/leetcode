/*
 * @lc app=leetcode id=459 lang=rust
 *
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (39.08%)
 * Total Accepted:    70K
 * Total Submissions: 179K
 * Testcase Example:  '"abab"'
 *
 * Given a non-empty string check if it can be constructed by taking a
 * substring of it and appending multiple copies of the substring together. You
 * may assume the given string consists of lowercase English letters only and
 * its length will not exceed 10000.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abab"
 * Output: True
 * Explanation: It's the substring "ab" twice.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aba"
 * Output: False
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "abcabcabcabc"
 * Output: True
 * Explanation: It's the substring "abc" four times. (And the substring
 * "abcabc" twice.)
 * 
 * 
 */
impl Solution {
    pub fn repeated_substring_pattern(s: String) -> bool {
        let n = s.len();

        let mut rest = n;
        let mut group_size = 2;
        while group_size <= rest {
            if rest % group_size == 0 {
                // match all substring

                // start from group count
                let mut group_count = n / group_size;
                // start from index 0
                let mut i = 0;

                while group_count < n {
                    // not match
                    if &s[group_count..group_count + 1] != &s[i..i + 1] {
                        break;
                    }
                    group_count += 1;
                    i += 1;
                }
                // bingo
                if group_count == n {
                    return true;
                }
                // remove same group size
                while rest % group_size == 0 {
                    rest /= group_size;
                }
            }

            group_size += 1;
        }

        false
    }
}
