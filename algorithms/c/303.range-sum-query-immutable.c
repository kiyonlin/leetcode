/*
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (32.45%)
 * Total Accepted:    95.1K
 * Total Submissions: 293K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * Example:
 * 
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * 
 */
typedef struct {
    int* nums;
    int numsSize
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize)
{
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->nums = nums;
    obj->numsSize = numsSize;
    return obj;
}

int numArraySumRange(NumArray* obj, int i, int j)
{
    int result = 0;
    for (int k = i; k <= j && k < obj->numsSize; k++) {
        result += obj->nums[k];
    }
    return result;
}

void numArrayFree(NumArray* obj)
{
    free(obj->nums);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */
