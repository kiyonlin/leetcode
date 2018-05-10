/*
 * [316] Remove Duplicate Letters
 *
 * https://leetcode.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Hard (30.54%)
 * Total Accepted:    40.6K
 * Total Submissions: 132.9K
 * Testcase Example:  '"bcabc"'
 *
 * 
 * Given a string which contains only lowercase letters, remove duplicate
 * letters so that every letter appear once and only once. You must make sure
 * your result is the smallest in lexicographical order among all possible
 * results.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given "bcabc"
 * Return "abc"
 * 
 * 
 * Given "cbacdcbc"
 * Return "acdb"
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
char* removeDuplicateLetters(char* s)
{
    int len = strlen(s);
    if (len < 2)
        return s;
    int count[26] = { 0 }, choosen[26] = { 0 }, rlen = 0;
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
        if (count[s[i] - 'a'] == 1)
            // get result string length
            rlen++;
    }
    char* result = (char*)malloc(sizeof(char) * (rlen + 1));
    for (int i = 0, j = 0; i < len; i++) {
        count[s[i] - 'a']--;
        if (choosen[s[i] - 'a'])
            continue;
        // while s[i] less than choosen char in result and has enough count
        // replace the choosen one
        while (j > 0 && s[i] < result[j - 1] && count[result[j - 1] - 'a'] > 0) {
            choosen[result[j - 1] - 'a'] = 0;
            j--;
        }
        // fill result string
        result[j++] = s[i];
        choosen[s[i] - 'a'] = 1;
    }
    result[rlen] = '\0';
    return result;
}
