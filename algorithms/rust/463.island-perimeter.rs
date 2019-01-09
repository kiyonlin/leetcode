/*
 * @lc app=leetcode id=463 lang=rust
 *
 * [463] Island Perimeter
 *
 * https://leetcode.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (59.63%)
 * Total Accepted:    114.3K
 * Total Submissions: 191.7K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * You are given a map in form of a two-dimensional integer grid where 1
 * represents land and 0 represents water.
 * 
 * Grid cells are connected horizontally/vertically (not diagonally). The grid
 * is completely surrounded by water, and there is exactly one island (i.e.,
 * one or more connected land cells).
 * 
 * The island doesn't have "lakes" (water inside that isn't connected to the
 * water around the island). One cell is a square with side length 1. The grid
 * is rectangular, width and height don't exceed 100. Determine the perimeter
 * of the island.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * [[0,1,0,0],
 * ⁠[1,1,1,0],
 * ⁠[0,1,0,0],
 * ⁠[1,1,0,0]]
 * 
 * Output: 16
 * 
 * Explanation: The perimeter is the 16 yellow stripes in the image below:
 * 
 * 
 * 
 * 
 */

impl Solution {
    pub fn island_perimeter(grid: Vec<Vec<i32>>) -> i32 {
        let mut cnt = 0;
        for (i, row) in grid.iter().enumerate() {
            for (j, col) in row.iter().enumerate() {
                if *col == 1 {
                    cnt += if i + 1 == grid.len() || grid[i + 1][j] == 0 { 1 } else { 0 };
                    cnt += if i == 0 || grid[i - 1][j] == 0 { 1 } else { 0 };
                    cnt += if j + 1 == grid[i].len() || grid[i][j + 1] == 0 { 1 } else { 0 };
                    cnt += if j == 0 || grid[i][j - 1] == 0 { 1 } else { 0 };
                }
            }
        }
        cnt
    }
}
