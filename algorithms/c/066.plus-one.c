/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (39.82%)
 * Total Accepted:    241.5K
 * Total Submissions: 606.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    if (!digits)
        return NULL;

    // 返回结果根据returnSize指针的值进行判断
    *returnSize = digitsSize;

    for (int i = digitsSize - 1; i >= 0; i--) {
        if (++(digits[i]) < 10)
            return digits;
        digits[i] = 0;
    }
    // 到这里都是 9...9 + 1 的结果
    // 重新分配内存
    digits = realloc(digits, ++(*returnSize) * sizeof(int));
    // 末尾置为0
    digits[*returnSize - 1] = 0;
    // 第一位置为1
    digits[0] = 1;

    return digits;
}
