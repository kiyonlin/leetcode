#
# [415] Add Strings
#
# https://leetcode.com/problems/add-strings/description/
#
# algorithms
# Easy (41.78%)
# Total Accepted:    62.4K
# Total Submissions: 149.4K
# Testcase Example:  '"0"\n"0"'
#
# Given two non-negative integers num1 and num2 represented as string, return
# the sum of num1 and num2.
#
# Note:
#
# The length of both num1 and num2 is < 5100.
# Both num1 and num2 contains only digits 0-9.
# Both num1 and num2 does not contain any leading zero.
# You must not use any built-in BigInteger library or convert the inputs to
# integer directly.
#
#
#


class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        len1, len2 = len(num1) - 1, len(num2) - 1
        l = max(len1, len2) + 1
        res = bytearray('0' * (l + 1), 'utf8')
        while len1 >= 0 or len2 >= 0:
            carry = res[l] - ord('0')
            if len1 >= 0:
                carry, len1 = carry + ord(num1[len1]) - ord('0'), len1 - 1
            if len2 >= 0:
                carry, len2 = carry + ord(num2[len2]) - ord('0'), len2 - 1
            res[l - 1], res[l], l = carry // 10 + ord('0'), carry % 10 + ord('0'), l - 1
        res = str(res).lstrip('0')
        return '0' if res == '' else res
