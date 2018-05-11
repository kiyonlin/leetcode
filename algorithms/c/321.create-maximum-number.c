/*
 * [321] Create Maximum Number
 *
 * https://leetcode.com/problems/create-maximum-number/description/
 *
 * algorithms
 * Hard (24.86%)
 * Total Accepted:    23.6K
 * Total Submissions: 94.9K
 * Testcase Example:  '[3,4,6,5]\n[9,1,2,5,8,3]\n5'
 *
 * 
 * ⁠   Given two arrays of length m and n with digits 0-9 representing two
 * numbers.
 * ⁠   Create the maximum number of length k  from digits of the two. The
 * relative order of the digits
 * ⁠   from the same array must be preserved. Return an array of the k digits.
 * You should try to optimize your time and space complexity.
 * 
 * 
 * 
 * ⁠   Example 1:
 * 
 * 
 * ⁠   nums1 = [3, 4, 6, 5]
 * ⁠   nums2 = [9, 1, 2, 5, 8, 3]
 * ⁠   k = 5
 * ⁠   return [9, 8, 6, 5, 3]
 * 
 * 
 * ⁠   Example 2:
 * 
 * 
 * ⁠   nums1 = [6, 7]
 * ⁠   nums2 = [6, 0, 4]
 * ⁠   k = 5
 * ⁠   return [6, 7, 6, 0, 4]
 * 
 * 
 * ⁠   Example 3:
 * 
 * 
 * ⁠   nums1 = [3, 9]
 * ⁠   nums2 = [8, 9]
 * ⁠   k = 3
 * ⁠   return [9, 8, 9]
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void maxNum(int*, int, int, int*);
void merge(int*, int, int*, int, int*);
void max(int*, int*, int);

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize)
{
    *returnSize = k;
    int* result = (int*)malloc(sizeof(int) * k);
    memset(result, 0, sizeof(int) * k);
    int* merged = (int*)malloc(sizeof(int) * k);
    int *max1 = NULL, *max2 = NULL;
    for (int i = 0; i <= k; i++) {
        int n1 = i, n2 = k - i;
        if (n1 > nums1Size || n2 > nums2Size)
            continue;
        max1 = realloc(max1, sizeof(int) * n1);
        maxNum(nums1, nums1Size, n1, max1);

        max2 = realloc(max2, sizeof(int) * n2);
        maxNum(nums2, nums2Size, n2, max2);

        merge(max1, n1, max2, n2, merged);

        max(result, merged, k);
    }
    free(max1), free(max2), free(merged);
    return result;
}

void maxNum(int* nums, int n, int k, int* r)
{
    for (int i = 0, j = 0; i < n; i++) {
        // drop last one
        while (j > 0 && k - j < n - i && nums[i] > r[j - 1])
            j--;
        if (j < k)
            r[j++] = nums[i];
    }
}
void merge(int* nums1, int n1, int* nums2, int n2, int* r)
{
    for (int i = 0, j = 0, k = 0; k < n1 + n2; k++) {
        int val1 = i < n1 ? nums1[i] : -1;
        int val2 = j < n2 ? nums2[j] : -1;
        int t = 1;
        while (val1 == val2 && val1 != -1) {
            val1 = i + t < n1 ? nums1[i + t] : -1;
            val2 = j + t < n2 ? nums2[j + t] : -1;
            t++;
        }
        if (val1 > val2)
            r[k] = nums1[i++];
        else if (val1 < val2)
            r[k] = nums2[j++];
        else
            // val1 == val2 ==  -1
            r[k] = nums1[i++];
    }
}
void max(int* nums1, int* nums2, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        if (nums1[i] < nums2[i])
            break;
        if (nums1[i] > nums2[i])
            return;
    }
    if (i != n)
        // set the new max
        for (i = 0; i < n; i++)
            nums1[i] = nums2[i];
}
