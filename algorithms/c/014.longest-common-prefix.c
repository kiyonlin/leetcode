/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.61%)
 * Total Accepted:    270.8K
 * Total Submissions: 856.1K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
char* longestCommonPrefix(char** strs, int strsSize)
{
    if (strsSize < 1)
        return "";
    if (strsSize == 1)
        return strs[0];
    int len = strlen(strs[0]), i;

    // 循环遍历每个字符，和其他字符串比较，不相等则结束
    for (i = 0; i < len; i++) {
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i])
                goto end;
        }
    }
end:
    strs[0][i] = '\0';
    return strs[0];
}
