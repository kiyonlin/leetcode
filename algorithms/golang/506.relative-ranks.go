/*
 * @lc app=leetcode id=506 lang=golang
 *
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (48.38%)
 * Total Accepted:    47.7K
 * Total Submissions: 96.9K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 
 * Given scores of N athletes, find their relative ranks and the people with
 * the top three highest scores, who will be awarded medals: "Gold Medal",
 * "Silver Medal" and "Bronze Medal".
 * 
 * Example 1:
 * 
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so
 * they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two
 * athletes, you just need to output their relative ranks according to their
 * scores.
 * 
 * 
 * 
 * Note:
 * 
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 * 
 * 
 * 
 */
func findRelativeRanks(nums []int) []string {
	t := make(map[int]int)
	for i, n := range nums {
		t[n] = i
	}

	sort.Ints(nums)

	ret := make([]string, len(nums))

	for i, rank := len(nums)-1, 1; i >= 0; i, rank = i-1, rank+1 {
		s := strconv.FormatInt(int64(rank), 10)
		switch {
		case rank == 1:
			s = "Gold Medal"
		case rank == 2:
			s = "Silver Medal"
		case rank == 3:
			s = "Bronze Medal"
		}
		ret[t[nums[i]]] = s
	}
	return ret
}
