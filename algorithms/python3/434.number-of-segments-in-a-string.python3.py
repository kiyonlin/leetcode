#
# [434] Number of Segments in a String
#
# https://leetcode.com/problems/number-of-segments-in-a-string/description/
#
# algorithms
# Easy (36.55%)
# Total Accepted:    42.2K
# Total Submissions: 115.4K
# Testcase Example:  '"Hello, my name is John"'
#
# Count the number of segments in a string, where a segment is defined to be a
# contiguous sequence of non-space characters.
#
# Please note that the string does not contain any non-printable characters.
#
# Example:
#
# Input: "Hello, my name is John"
# Output: 5
#
#
#


class Solution:
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        return len([k for k in s.split(' ') if k != ''])
