/*
 * @lc app=leetcode id=820 lang=golang
 *
 * [820] Short Encoding of Words
 *
 * https://leetcode.com/problems/short-encoding-of-words/description/
 *
 * algorithms
 * Medium (50.70%)
 * Total Accepted:    13.7K
 * Total Submissions: 27.1K
 * Testcase Example:  '["time", "me", "bell"]'
 *
 * Given a list of words, we may encode it by writing a reference string S and
 * a list of indexes A.
 * 
 * For example, if the list of words is ["time", "me", "bell"], we can write it
 * as S = "time#bell#" and indexes = [0, 2, 5].
 * 
 * Then for each index, we will recover the word by reading from the reference
 * string from that index until we reach a "#" character.
 * 
 * What is the length of the shortest reference string S possible that encodes
 * the given words?
 * 
 * Example:
 * 
 * 
 * Input: words = ["time", "me", "bell"]
 * Output: 10
 * Explanation: S = "time#bell#" and indexes = [0, 2, 5].
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= words.length <= 2000.
 * 1 <= words[i].length <= 7.
 * Each word has only lowercase letters.
 * 
 * 
 */

func minimumLengthEncoding(words []string) int {
	t := &trie{children: make(map[byte]*trie)}
	for _, word := range words {
		t.insert(reverse(word))
	}
	return getLength(t, 1)
}

type trie struct {
	end      bool
	children map[byte]*trie
}

func (t *trie) insert(word string) {
	root := t
	for _, c := range word {
		i := byte(c - 'a')
		if _, ok := root.children[i]; !ok {
			root.children[i] = &trie{children: make(map[byte]*trie)}
		}
		root = root.children[i]
	}
	root.end = true
}

func getLength(t *trie, level int) int {
	l := 0
	for _, child := range t.children {
		if child.end && len(child.children) == 0 {
			l += level + 1 // 1 for #
		}
		l += getLength(child, level+1)
	}
	return l
}

func reverse(s string) string {
	b := []rune(s)
	for i, j := 0, len(b)-1; i < j; i, j = i+1, j-1 {
		b[i], b[j] = b[j], b[i]
	}
	return string(b)
}
