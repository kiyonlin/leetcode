#
# [409] Longest Palindrome
#
# https://leetcode.com/problems/longest-palindrome/description/
#
# algorithms
# Easy (46.18%)
# Total Accepted:    70.1K
# Total Submissions: 151.9K
# Testcase Example:  '"abccccdd"'
#
# Given a string which consists of lowercase or uppercase letters, find the
# length of the longest palindromes that can be built with those letters.
#
# This is case sensitive, for example "Aa" is not considered a palindrome
# here.
#
# Note:
# Assume the length of given string will not exceed 1,010.
#
#
# Example:
#
# Input:
# "abccccdd"
#
# Output:
# 7
#
# Explanation:
# One longest palindrome that can be built is "dccaccd", whose length is 7.
#
#
#

from collections import defaultdict


class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        t = defaultdict(int)
        for c in list(s):
            t[c] += 1
        total = 0
        odd = False
        for c in t:
            if t[c] % 2 == 0:
                total += t[c]
            else:
                total += t[c] - 1
                odd = True
        if odd:
            total += 1
        return total
