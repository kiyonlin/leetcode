/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (29.06%)
 * Total Accepted:    269.8K
 * Total Submissions: 928.5K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
int strStr(char* haystack, char* needle)
{
    if (!*needle)
        return 0;
    if (!*haystack)
        return -1;
    int sublen = strlen(needle);
    int len = strlen(haystack) - sublen, i;
    for (i = 0; i <= len; i++) {
        // 找第一个相等的字母
        if (haystack[i] == needle[0]) {
            int j;
            // 找到以后往下匹配
            for (j = 1; j < sublen; j++) {
                if (haystack[i + j] != needle[j])
                    break;
            }
            // 找到结果就返回
            if (j == sublen)
                return i;
        }
    }
    return -1;
}
