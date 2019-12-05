/*
 * @lc app=leetcode id=49 lang=golang
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (47.07%)
 * Total Accepted:    443.6K
 * Total Submissions: 868.9K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */
func groupAnagrams(strs []string) [][]string {
	ret := make([][]string, 0)
	group := make(map[[26]byte]int)
	for _, str := range strs {
		key := [26]byte{}
		for _, c := range str {
			key[c-'a']++
		}
		if index, ok := group[key]; ok {
			ret[index] = append(ret[index], str)
		} else {
			ret = append(ret, []string{str})
			group[key] = len(ret) - 1
		}
	}
	return ret
}
