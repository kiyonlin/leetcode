/*
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (47.27%)
 * Total Accepted:    137.9K
 * Total Submissions: 291.7K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 * 
 * Note:
 * 
 * 
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    *returnSize = 2;
    int* result = (int*)malloc(sizeof(int) * 2);
    int i = 0, j = numbersSize - 1;
    // 因为已经排序而且必定有答案，所以可以从两头向中间遍历
    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum == target)
            break;
        if (sum > target)
            j--;
        else
            i++;
    }
    result[0] = i + 1, result[1] = j + 1;
    return result;
}
