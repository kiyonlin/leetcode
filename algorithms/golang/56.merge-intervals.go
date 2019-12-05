/*
 * @lc app=leetcode id=56 lang=golang
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (35.74%)
 * Total Accepted:    455K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */
func merge(intervals [][]int) [][]int {
	if len(intervals) == 0 {
		return [][]int{}
	}
	sort.Sort(Intervals(intervals))
	ret := make([][]int, 0)
	cur := intervals[0]
	for i := 1; i < len(intervals); i++ {
		if intervals[i][0] > cur[1] {
			ret = append(ret, append(make([]int, 0), cur...))
			cur = intervals[i]
		} else if intervals[i][1] > cur[1] {
			cur[1] = intervals[i][1]
		}
	}
	ret = append(ret, cur)
	return ret
}

type Intervals [][]int

func (a Intervals) Len() int {
	return len(a)
}

func (a Intervals) Less(i, j int) bool {
	if a[i][0] < a[j][0] || (a[i][0] == a[j][0] && a[i][1] < a[j][1]) {
		return true
	}
	return false
}

func (a Intervals) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}
