#
# [447] Number of Boomerangs
#
# https://leetcode.com/problems/number-of-boomerangs/description/
#
# algorithms
# Easy (47.27%)
# Total Accepted:    40.3K
# Total Submissions: 85.3K
# Testcase Example:  '[[0,0],[1,0],[2,0]]'
#
# Given n points in the plane that are all pairwise distinct, a "boomerang" is
# a tuple of points (i, j, k) such that the distance between i and j equals the
# distance between i and k (the order of the tuple matters).
# 
# Find the number of boomerangs. You may assume that n will be at most 500 and
# coordinates of points are all in the range [-10000, 10000] (inclusive).
# 
# Example:
# 
# Input:
# [[0,0],[1,0],[2,0]]
# 
# Output:
# 2
# 
# Explanation:
# The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
# 
# 
#
class Solution:
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        count = 0
        for [x1, y1] in points:
            distances = {}
            for [x2, y2] in points:
                # (y1 - y2) * (y1 - y2) 效率比 (y1 - y2) ** 2 高
                distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
                if distance in distances:
                    count += distances[distance]
                    distances[distance] += 1
                else:
                    distances[distance] = 1
        
        return 2 * count
        
