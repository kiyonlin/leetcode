/*
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (47.26%)
 * Total Accepted:    128.6K
 * Total Submissions: 272K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
int firstUniqChar(char* s)
{
    int count[26] = { 0 }, len = strlen(s);
    for (int i = 0; i < len; i++)
        count[s[i] - 'a']++;
    for (int i = 0; i < len; i++)
        if (count[s[i] - 'a'] == 1)
            return i;
    return -1;
}
