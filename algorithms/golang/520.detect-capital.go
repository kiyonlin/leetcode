/*
 * @lc app=leetcode id=520 lang=golang
 *
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (52.49%)
 * Total Accepted:    96K
 * Total Submissions: 181.7K
 * Testcase Example:  '"USA"'
 *
 * Given a word, you need to judge whether the usage of capitals in it is right
 * or not.
 * 
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 * 
 * 
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital, like "Google".
 * 
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "USA"
 * Output: True
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "FlaG"
 * Output: False
 * 
 * 
 * 
 * 
 * Note: The input will be a non-empty word consisting of uppercase and
 * lowercase latin letters.
 * 
 */
func detectCapitalUse(word string) bool {
	if len(word) == 1 {
		return true
	}
	// 第一个字母大写，则判断剩余字母
	if word[0] < 97 {
		return isCapitalUse(word[1:])
	}
	return isCapitalUse(word)
}

func isCapitalUse(word string) bool {
	isUpper := word[0] < 97
	for i := 1; i < len(word); i++ {
		// 第一个字母大写，后面出现小写则不是
		if isUpper && word[i] >= 97 {
			return false
		}
		// 第一个字母小写，后面出现大写则不是
		if !isUpper && word[i] < 97 {
			return false
		}
	}
	return true
}
