/*
 * @lc app=leetcode id=500 lang=golang
 *
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (62.28%)
 * Total Accepted:    98K
 * Total Submissions: 155.2K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * Given a List of words, return the words that can be typed using letters of
 * alphabet on only one row's of American keyboard like the image
 * below.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You may use one character in the keyboard more than once.
 * You may assume the input string will only contain letters of alphabet.
 * 
 * 
 */
func findWords(words []string) []string {
	table := [26]int{2, 4, 4, 2, 1, 2, 2, 2, 1, 2, 2, 2, 4, 4, 1, 1, 1, 1, 2, 1, 1, 4, 1, 4, 1, 4}

	r := make([]string, 0, len(words))
	for _, word := range words {
		if len(word) == 1 {
			r = append(r, word)
			continue
		}
		flag := 0
		for _, c := range word {
			// 累积结果
			flag |= table[unicode.ToLower(c)-'a']
		}
		// 判断结果是否为2的次方
		if (flag & (flag - 1)) == 0 {
			r = append(r, word)
		}
	}

	return r
}
