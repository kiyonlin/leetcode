/*
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (27.37%)
 * Total Accepted:    208.8K
 * Total Submissions: 761K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 找规律
 * i 为行数，k 为第 i 行的第 k 个字符
 * 0，n行是特殊行，字符下标为 2*k*(n-1)+i
 * 1～n-1行，偶数个字符的下标为 k*(n-1)+i，奇数个字符的下标，是下一个字符的下标减去2*i即 (k+1)*(n-1)+i-2i
 */
char* convert(char* s, int numRows)
{
    int len = strlen(s);

    if (numRows < 2 || len <= numRows)
        return s;
    char* result = malloc(sizeof(char) * len + 1);
    result[len] = '\0';

    for (int i = 0, j = 0; i < numRows; i++) {
        int char_index, k = 0;
        while (1) {
            if (i == 0 || i == numRows - 1) {
                char_index = 2 * k * (numRows - 1) + i;
            } else {
                char_index = k % 2 ? (k + 1) * (numRows - 1) + i - 2 * i : k * (numRows - 1) + i;
            }
            if (char_index >= len) {
                break;
            }
            result[j++] = s[char_index];
            k++;
        }
    }
    return result;
}
