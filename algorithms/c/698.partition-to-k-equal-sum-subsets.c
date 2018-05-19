/*
 * [698] Partition to K Equal Sum Subsets
 *
 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (37.81%)
 * Total Accepted:    14.8K
 * Total Submissions: 39.2K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * Given an array of integers nums and a positive integer k, find whether it's
 * possible to divide this array into k non-empty subsets whose sums are all
 * equal.
 * 
 * Example 1:
 * 
 * Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * Output: True
 * Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3),
 * (2,3) with equal sums.
 * 
 * 
 * 
 * Note:
 * 1 .
 * 0 < nums[i] < 10000.
 * 
 */
bool canPartition(int* nums, int size, bool* visited, int start, int target)
{
    for (int i = start; i < size; i++) {
        if (visited[i])
            continue;
        if (nums[i] == target) {
            visited[i] = true;
            return true;
        } else if (nums[i] > target)
            continue;
        visited[i] = true;
        if (canPartition(nums, size, visited, start + 1, target - nums[i]))
            return true;
        visited[i] = false;
    }
    return false;
}

int cmp(void* a, void* b) { return *(int*)b - *(int*)a; }

bool canPartitionKSubsets(int* nums, int numsSize, int k)
{
    if (numsSize < k || k < 1)
        return false;
    if (k == 1)
        return true;
    int sum = 0;
    bool visited[numsSize];
    for (int i = 0; i < numsSize; i++)
        sum += nums[i], visited[i] = false;
    if (sum % k)
        return false;
    sum /= k;
    qsort(nums, numsSize, sizeof(int), cmp);
    if (nums[0] > sum)
        return false;
    for (int i = 0; i < numsSize; i++) {
        if (visited[i])
            continue;
        if (nums[i] == sum) {
            visited[i] = true;
            continue;
        }
        visited[i] = true;
        if (!canPartition(nums, numsSize, visited, i + 1, sum - nums[i]))
            return false;
    }
    return true;
}
