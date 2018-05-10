/*
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (21.07%)
 * Total Accepted:    124.4K
 * Total Submissions: 590.6K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*'.
 * 
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like ? or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "cb"
 * p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "adceb"
 * p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*'
 * matches the substring "dce".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "acdcb"
 * p = "a*c?b"
 * Output: false
 * 
 * 
 */
bool isMatch(char* s, char* p)
{
    char *ss = NULL, *pp = NULL;
    while (*s) {
        if (*p == '?' || *p == *s) {
            p++, s++;
        } else if (*p == '*') {
            // save state of p
            pp = ++p;
            ss = s;
        } else if (pp != NULL) {
            // load state of p
            p = pp;
            s = ++ss;
        } else
            return false;
    }
    while (*p == '*')
        p++;

    return !*s && !*p;
}
