/*
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (34.84%)
 * Total Accepted:    137.1K
 * Total Submissions: 393.4K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */
bool isIsomorphic(char* s, char* t)
{
    int ms[256] = { 0 }, mt[256] = { 0 }, len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (ms[s[i]] != mt[t[i]])
            return false;
        // 映射到同一下标，全部+1，避免和初始化的值相同
        ms[s[i]] = mt[t[i]] = i + 1;
    }
    return true;
}
