/*
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (33.53%)
 * Total Accepted:    104.1K
 * Total Submissions: 310.4K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * ⁠Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Examples:
 * 
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * 
 * 
 * 
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters separated by a single space.
 * 
 * 
 * Credits:Special thanks to @minglotus6 for adding this problem and creating
 * all test cases.
 */
bool wordPattern(char* pattern, char* str)
{
    int table[26] = { 0 };
    for (; *pattern && *str; pattern++) {
        // 计算单词的hash值
        int hash = 0;
        for (; *str && *str != ' '; str++) {
            hash = 31 * hash + (*str);
        }
        // 跳过空格
        if (*str)
            str++;

        // hash table没标记，则进行标记
        if (!table[*pattern - 'a']) {
            // 判断其他字母有没有占据同一个hash
            // '"abba"\n"dog dog dog dog"'
            for (int i = 0; i < 26; i++) {
                if (table[i] == hash)
                    return false;
            }
            table[*pattern - 'a'] = hash;
        }
        // 同一个字母应该是同一个hash
        if (table[*pattern - 'a'] != hash) {
            return false;
        }
    }
    return !*str && !*pattern;
}
