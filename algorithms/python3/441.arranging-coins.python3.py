#
# [441] Arranging Coins
#
# https://leetcode.com/problems/arranging-coins/description/
#
# algorithms
# Easy (36.68%)
# Total Accepted:    50.7K
# Total Submissions: 138.2K
# Testcase Example:  '5'
#
# You have a total of n coins that you want to form in a staircase shape, where
# every k-th row must have exactly k coins.
# ⁠
# Given n, find the total number of full staircase rows that can be formed.
# 
# n is a non-negative integer and fits within the range of a 32-bit signed
# integer.
# 
# Example 1:
# 
# n = 5
# 
# The coins can form the following rows:
# ¤
# ¤ ¤
# ¤ ¤
# 
# Because the 3rd row is incomplete, we return 2.
# 
# 
# 
# Example 2:
# 
# n = 8
# 
# The coins can form the following rows:
# ¤
# ¤ ¤
# ¤ ¤ ¤
# ¤ ¤
# 
# Because the 4th row is incomplete, we return 3.
# 
# 
#
import math

class Solution:
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        res = int(math.sqrt(n * 2))
        return res if res * (res + 1) <= n * 2 else res - 1
        
