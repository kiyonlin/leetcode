/*
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (44.22%)
 * Total Accepted:    111.5K
 * Total Submissions: 252.2K
 * Testcase Example:  '[]\n[]'
 *
 * 
 * Given two arrays, write a function to compute their intersection.
 * 
 * 
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 * 
 * 
 * Note:
 * 
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 * 
 * 
 * 
 * Follow up:
 * 
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 用a-b排序时包含-2147483648会出错
int cmp(void* a, void* b) { return *(int*)a < *(int*)b ? -1 : (*(int*)a == *(int*)b ? 0 : 1); }

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    *returnSize = 0;
    int size = nums1Size > nums2Size ? nums1Size : nums2Size;
    int* result = (int*)malloc(size * sizeof(int));
    int i = 0, j = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            result[(*returnSize)++] = nums1[i], i++, j++;
        } else if (nums1[i] < nums2[j])
            i++;
        else
            j++;
    }
    return result;
}
