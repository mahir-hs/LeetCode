--
-- @lc app=leetcode id=184 lang=mysql
--
-- [184] Department Highest Salary
--

-- @lc code=start
# Write your MySQL query statement below
SELECT Department.name AS Department,Employee.name AS Employee, Employee.salary AS Salary 
FROM Employee JOIN Department ON Employee.departmentId = Department.id
WHERE (SELECT MAX(Salary) FROM Employee WHERE Employee.departmentId = Department.id) = Employee.salary

-- @lc code=end

