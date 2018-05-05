/*
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (48.66%)
 * Total Accepted:    167.4K
 * Total Submissions: 344K
 * Testcase Example:  '"A"'
 *
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 * 
 * For example:
 * 
 * 
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "A"
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "AB"
 * Output: 28
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "ZY"
 * Output: 701
 * 
 * 
 */

int titleToNumber(char* s)
{
    int result = 0;
    while (*s) {
        result = result * 26 + (*s++ - 'A' + 1);
    }
    return result;
    // int len = strlen(s), result = 0;
    // for (int i = len - 1; i >= 0; i--) {
    //     result += pow(26, i) * (s[len - i - 1] - 'A' + 1);
    // }
    // return result;
}
