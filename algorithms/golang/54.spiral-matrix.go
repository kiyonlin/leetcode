/*
 * @lc app=leetcode id=54 lang=golang
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (30.57%)
 * Total Accepted:    291.3K
 * Total Submissions: 907.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
var (
	visited    [][]bool
	DIRECTIONS = [4][2]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
)

func spiralOrder(matrix [][]int) []int {
	if len(matrix) == 0 {
		return []int{}
	}
	initVisited(len(matrix), len(matrix[0]))

	ret := make([]int, 0)
	travel(matrix, 0, 0, 0, &ret)
	return ret
}

func travel(matrix [][]int, i, j, currentDirection int, ret *[]int) bool {
	if i == -1 || i == len(matrix) || j == -1 || j == len(matrix[0]) || visited[i][j] {
		return false
	}

	*ret = append(*ret, matrix[i][j])
	visited[i][j] = true

	ii, jj := i+DIRECTIONS[currentDirection][0], j+DIRECTIONS[currentDirection][1]
	if !travel(matrix, ii, jj, currentDirection, ret) {
		currentDirection = (currentDirection + 1) % 4
		ii, jj := i+DIRECTIONS[currentDirection][0], j+DIRECTIONS[currentDirection][1]
		travel(matrix, ii, jj, currentDirection, ret)
	}
	return true
}

func initVisited(m, n int) {
	visited = make([][]bool, m)
	for i := 0; i < m; i++ {
		visited[i] = make([]bool, n)
	}
}
