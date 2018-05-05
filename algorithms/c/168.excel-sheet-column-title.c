/*
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (27.38%)
 * Total Accepted:    135.8K
 * Total Submissions: 495.8K
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 * 
 * For example:
 * 
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "A"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 28
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 701
 * Output: "ZY"
 * 
 * 
 */
char* convertToTitle(int n)
{
    char* result = malloc(sizeof(char));
    int len = 1;
    while (n) {
        result[len - 1] = --n % 26 + 'A';
        result = realloc(result, (++len) * sizeof(char));
        n /= 26;
    }
    result[len - 1] = '\0';
    int i = 0, j = len - 2;
    while (i < j) {
        result[i] = result[i] ^ result[j];
        result[j] = result[i] ^ result[j];
        result[i] = result[i] ^ result[j];
        i++, j--;
    }
    return result;
}
