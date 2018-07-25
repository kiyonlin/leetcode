#
# [412] Fizz Buzz
#
# https://leetcode.com/problems/fizz-buzz/description/
#
# algorithms
# Easy (58.00%)
# Total Accepted:    131.1K
# Total Submissions: 226.1K
# Testcase Example:  '1'
#
# Write a program that outputs the string representation of numbers from 1 to
# n.
#
# But for multiples of three it should output “Fizz” instead of the number and
# for the multiples of five output “Buzz”. For numbers which are multiples of
# both three and five output “FizzBuzz”.
#
# Example:
#
# n = 15,
#
# Return:
# [
# ⁠   "1",
# ⁠   "2",
# ⁠   "Fizz",
# ⁠   "4",
# ⁠   "Buzz",
# ⁠   "Fizz",
# ⁠   "7",
# ⁠   "8",
# ⁠   "Fizz",
# ⁠   "Buzz",
# ⁠   "11",
# ⁠   "Fizz",
# ⁠   "13",
# ⁠   "14",
# ⁠   "FizzBuzz"
# ]
#
#
#


class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ret = []
        for i in range(1, n+1):
            if i % 3 == 0 and i % 5 == 0:
                ret.append('FizzBuzz')
            elif i % 3 == 0:
                ret.append('Fizz')
            elif i % 5 == 0:
                ret.append('Buzz')
            else:
                ret.append(str(i))
        return ret
