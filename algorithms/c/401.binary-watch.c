/*
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (44.75%)
 * Total Accepted:    48.8K
 * Total Submissions: 109K
 * Testcase Example:  '0'
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and
 * the 6 LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the
 * right.
 * 
 * For example, the above binary watch reads "3:25".
 * 
 * Given a non-negative integer n which represents the number of LEDs that are
 * currently on, return all possible times the watch could represent.
 * 
 * Example:
 * Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04",
 * "0:08", "0:16", "0:32"]
 * 
 * 
 * Note:
 * 
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid,
 * it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for
 * example "10:2" is not valid, it should be "10:02".
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int getOnes(int n)
{
    int count = 0;
    while (n)
        count += n & 1, n >>= 1;
    return count;
}

char** readBinaryWatch(int num, int* returnSize)
{
    char** result = NULL;
    *returnSize = 0;
    for (int i = 0; i < 12; i++) {
        int c1 = getOnes(i);
        for (int j = 0; j < 60; j++) {
            int c2 = getOnes(j);
            if (c1 + c2 == num) {
                result = (char**)realloc(result, sizeof(char*) * (++*returnSize));
                result[*returnSize - 1] = (char*)malloc(sizeof(char) * 6);
                sprintf(result[*returnSize - 1], "%d:%02d", i, j);
            }
        }
    }
    return result;
}
