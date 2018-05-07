/*
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (47.68%)
 * Total Accepted:    214.1K
 * Total Submissions: 449K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, write a function to determine if t is an anagram
 * of s.
 * 
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */
bool isAnagram(char* s, char* t)
{
    int slen = strlen(s), tlen = strlen(t);
    if (slen != tlen)
        return false;
    int* hashTable = (int*)malloc(sizeof(int) * 26);
    memset(hashTable, 0, sizeof(int) * 26);
    for (int i = 0; i < slen; i++) {
        hashTable[s[i] - 'a']++;
    }
    for (int i = 0; i < tlen; i++) {
        if (--hashTable[t[i] - 'a'] < 0)
            return false;
    }
    return true;
}
