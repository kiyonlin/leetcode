/*
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (48.31%)
 * Total Accepted:    132.1K
 * Total Submissions: 273.5K
 * Testcase Example:  '[]\n[]'
 *
 * 
 * Given two arrays, write a function to compute their intersection.
 * 
 * 
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 * 
 * 
 * Note:
 * 
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(void* a, void* b)
{
    return *(int*)a - *(int*)b;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int* result = NULL;
    *returnSize = 0;
    for (int i = 0; i < nums1Size; i++) {
        // 在数组2中二分查找
        int* found = bsearch(&nums1[i], nums2, nums2Size, sizeof(int), cmp);

        if (found) {
            // 找到了的话判断结果集里有没有
            if (NULL == bsearch((int*)found, result, *returnSize, sizeof(int), cmp)) {
                result = realloc(result, ++(*returnSize) * sizeof(int));
                result[*returnSize - 1] = *(int*)found;
            }
        }
    }
    return result;
}
