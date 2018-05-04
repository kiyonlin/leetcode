/*
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.07%)
 * Total Accepted:    190.6K
 * Total Submissions: 594.4K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
int lengthOfLastWord(char* s)
{
    int len = strlen(s), i;
    if (len == 0)
        return 0;
    // 去掉末尾的空格
    for (i = len - 1; i >= 0; i--) {
        if (s[i] == ' ')
            continue;
        else
            break;
    }
    if (i == -1)
        return 0;
    int result = 0;
    for (; i >= 0; i--) {
        if (s[i] == ' ')
            return result;
        result++;
    }
    return result;
}
