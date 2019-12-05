/*
 * @lc app=leetcode id=59 lang=golang
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (46.80%)
 * Total Accepted:    163.2K
 * Total Submissions: 325.8K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */
func generateMatrix(n int) [][]int {
	ret := make([][]int, n)
	for i := 0; i < n; i++ {
		ret[i] = make([]int, n)
	}
	dr := []int{0, 1, 0, -1}
	dc := []int{1, 0, -1, 0}
	r, c, di := 0, 0, 0
	for i := 1; i <= n*n; i++ {
		ret[r][c] = i
		nr := r + dr[di]
		nc := c + dc[di]
		// 不合法时转向
		if nr == -1 || nr == n || nc == -1 || nc == n || ret[nr][nc] != 0 {
			di = (di + 1) % 4
			r += dr[di]
			c += dc[di]
		} else {
			r, c = nr, nc
		}
	}
	return ret
}
