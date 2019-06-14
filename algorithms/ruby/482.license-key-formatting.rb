#
# @lc app=leetcode id=482 lang=ruby
#
# [482] License Key Formatting
#
# https://leetcode.com/problems/license-key-formatting/description/
#
# algorithms
# Easy (40.98%)
# Total Accepted:    80.8K
# Total Submissions: 197.2K
# Testcase Example:  '"5F3Z-2e-9-w"\n4'
#
# You are given a license key represented as a string S which consists only
# alphanumeric character and dashes. The string is separated into N+1 groups by
# N dashes.
# 
# Given a number K, we would want to reformat the strings such that each group
# contains exactly K characters, except for the first group which could be
# shorter than K, but still must contain at least one character. Furthermore,
# there must be a dash inserted between two groups and all lowercase letters
# should be converted to uppercase.
# 
# Given a non-empty string S and a number K, format the string according to the
# rules described above.
# 
# Example 1:
# 
# Input: S = "5F3Z-2e-9-w", K = 4
# 
# Output: "5F3Z-2E9W"
# 
# Explanation: The string S has been split into two parts, each part has 4
# characters.
# Note that the two extra dashes are not needed and can be removed.
# 
# 
# 
# 
# Example 2:
# 
# Input: S = "2-5g-3-J", K = 2
# 
# Output: "2-5G-3J"
# 
# Explanation: The string S has been split into three parts, each part has 2
# characters except the first part as it could be shorter as mentioned
# above.
# 
# 
# 
# Note:
# 
# The length of string S will not exceed 12,000, and K is a positive integer.
# String S consists only of alphanumerical characters (a-z and/or A-Z and/or
# 0-9) and dashes(-).
# String S is non-empty.
# 
# 
#
# @param {String} s
# @param {Integer} k
# @return {String}
def license_key_formatting(s, k)
  # 一行
  # s.upcase.tr('-', '').reverse.scan(/.{1,#{k}}/).join('-').reverse
  s.delete! '-'
  len = s.length
  head = len % k
  step = len / k

  return s if step == 0

  result = ''
  if head > 0
    result << s[0, head] << '-'
  end

  step.times do |i|
    result << s[head + i * k, k]
    if i < step - 1
      result << '-'
    end
  end
  result.upcase
end

if __FILE__ == $0
  puts "0123456789", license_key_formatting("0123456789", 10)
  puts "0", license_key_formatting("0", 2)
  puts '5F3Z-2e-9-w', license_key_formatting('5F3Z-2e-9-w', 4)
  puts '2-5g-3-J', license_key_formatting('2-5g-3-J', 2)
  puts 'jfu7-djgu2-djg8j-38tg-928d', license_key_formatting('jfu7-djgu2-djg8j-38tg-928d', 5)
end