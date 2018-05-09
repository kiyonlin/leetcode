/*
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (42.43%)
 * Total Accepted:    33.4K
 * Total Submissions: 78.7K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks.Tasks could
 * be done without original order. Each task could be done in one interval. For
 * each interval, CPU could finish one task or just be idle.
 * 
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle. 
 * 
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 * 
 * Example 1:
 * 
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * 
 * 
 * 
 * Note:
 * 
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 * 
 * 
 */
int leastInterval(char* tasks, int tasksSize, int n)
{
    int table[26] = { 0 };
    for (int i = 0; i < tasksSize; i++) {
        table[tasks[i] - 'A']++;
    }
    // count 为数量最多的任务的个数
    int max = 0, count = 1;
    for (int i = 0; i < 26; i++) {
        if (table[i] == 0)
            continue;
        if (table[i] > max) {
            max = table[i];
            count = 1;
        } else if (table[i] == max) {
            count++;
        }
    }
    int intervals = (n + 1) * (max - 1) + count;
    return intervals > tasksSize ? intervals : tasksSize;
}
