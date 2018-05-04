/*
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (32.21%)
 * Total Accepted:    234.5K
 * Total Submissions: 728.1K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */
void merge(int* nums1, int m, int* nums2, int n)
{
    int len = m + n;
    for (int i = 0, j = 0, k = 0; i < len; i++) {
        int a = m - j - 1 >= 0 ? nums1[m - j - 1] : INT_MIN;
        int b = n - k - 1 >= 0 ? nums2[n - k - 1] : INT_MIN;
        // 从a和b中选一个
        if (a > b) {
            nums1[len - i - 1] = a;
            j++;
        } else {
            nums1[len - i - 1] = b;
            k++;
        }
    }
}
