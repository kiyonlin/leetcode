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


class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        t = {}
        for c in s:
            t[c] = t.get(c, 0) + 1
        total = 0
        odd = False
        for v in t.values():
            if v & 1 == 0:
                total += v
            elif not odd:
                total += v
                odd = True
            else:
                total += v - 1
        return total
