#
# [176] Second Highest Salary
#
# https://leetcode.com/problems/second-highest-salary/description/
#
# database
# Easy (23.17%)
# Total Accepted:    70.8K
# Total Submissions: 305.6K
# Testcase Example:  '{"headers": {"Employee": ["Id", "Salary"]}, "rows": {"Employee": [[1, 100], [2, 200], [3, 300]]}}'
#
# Write a SQL query to get the second highest salary from the Employee table.
#
#
# +----+--------+
# | Id | Salary |
# +----+--------+
# | 1  | 100    |
# | 2  | 200    |
# | 3  | 300    |
# +----+--------+
#
#
# For example, given the above Employee table, the query should return 200 as
# the second highest salary. If there is no second highest salary, then the
# query should return null.
#
#
# +---------------------+
# | SecondHighestSalary |
# +---------------------+
# | 200                 |
# +---------------------+
#
#
#
# Write your MySQL query statement below
select
    max(Salary) as SecondHighestSalary
from
    Employee
where
    Salary not in (
        select
            max(Salary)
        from
            Employee
    )