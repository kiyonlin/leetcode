/*
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (31.66%)
 * Total Accepted:    212.9K
 * Total Submissions: 672.2K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */
bool wordBreak(char* s, char** wordDict, int wordDictSize)
{
    int len = strlen(s);
    bool* dp = calloc(len + 1, sizeof(bool));
    dp[0] = true;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < wordDictSize; j++) {
            if (dp[i]) {
                // 在s+i中获取和字典相同长度的字符串进行比较
                int l = strlen(wordDict[j]);
                char str[l + 1];
                strncpy(str, s + i, l);
                str[l] = '\0';

                if (strcmp(str, wordDict[j]) == 0)
                    dp[i + l] = true;
            }
        }
    }
    return dp[len];
}
