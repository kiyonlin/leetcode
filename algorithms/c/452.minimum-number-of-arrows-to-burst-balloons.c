/*
 * [452] Minimum Number of Arrows to Burst Balloons
 *
 * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
 *
 * algorithms
 * Medium (44.45%)
 * Total Accepted:    22.1K
 * Total Submissions: 49.9K
 * Testcase Example:  '[[10,16],[2,8],[1,6],[7,12]]'
 *
 * There are a number of spherical balloons spread in two-dimensional space.
 * For each balloon, provided input is the start and end coordinates of the
 * horizontal diameter. Since it's horizontal, y-coordinates don't matter and
 * hence the x-coordinates of start and end of the diameter suffice. Start is
 * always smaller than end. There will be at most 104 balloons.
 * 
 * An arrow can be shot up exactly vertically from different points along the
 * x-axis. A balloon with xstart and xend bursts by an arrow shot at x if
 * xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be
 * shot. An arrow once shot keeps travelling up infinitely. The problem is to
 * find the minimum number of arrows that must be shot to burst all balloons. 
 * 
 * Example:
 * 
 * Input:
 * [[10,16], [2,8], [1,6], [7,12]]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * One way is to shoot one arrow for example at x = 6 (bursting the balloons
 * [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two
 * balloons).
 * 
 * 
 */
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
// 按结束升序
int cmp(void* aa, void* bb)
{
    int* a = *(int**)aa;
    int* b = *(int**)bb;
    return a[0] == b[0] ? a[1] - b[1] : a[0] - b[0];
}

// 寻找重合的线段(点)
// 排序后遍历，更新起点和终点
int findMinArrowShots(int** points, int pointsRowSize, int pointsColSize)
{
    if (pointsRowSize < 2)
        return pointsRowSize;
    qsort(points, pointsRowSize, sizeof(int*), cmp);
    int count = 1, start = points[0][0], end = points[0][1];
    for (int i = 1; i < pointsRowSize; i++) {
        if (points[i][0] > end) {
            count++;
            start = points[i][1];
            end = points[i][1];
        } else {
            start = max(start, points[i][0]);
            end = min(end, points[i][1]);
        }
    }
    return count;
}
