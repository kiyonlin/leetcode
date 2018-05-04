/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (34.21%)
 * Total Accepted:    200.7K
 * Total Submissions: 586.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
char* addBinary(char* a, char* b)
{
    int alen = strlen(a), blen = strlen(b);
    int len = alen > blen ? alen : blen;
    char* result = malloc(sizeof(char) * (len + 2));
    result[len + 1] = 0, result[1] = '0';
    int carry = 0;
    for (int i = 0; i < len; i++) {
        int abit = 0, bbit = 0;
        if (alen - i - 1 >= 0 && a[alen - i - 1] == '1')
            abit = 1;
        if (blen - i - 1 >= 0 && b[blen - i - 1] == '1')
            bbit = 1;
        result[len - i] = '0' + (carry + abit + bbit) % 2;
        carry = (carry + abit + bbit) / 2;
    }
    if (carry == 1) {
        result[0] = '1';
        return result;
    } else {
        return result + 1;
    }
}
