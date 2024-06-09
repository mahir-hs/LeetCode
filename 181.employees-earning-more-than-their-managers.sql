--
-- @lc app=leetcode id=181 lang=mysql
--
-- [181] Employees Earning More Than Their Managers
--

-- @lc code=start
# Write your MySQL query statement below

SELECT e.name AS Employee
FROM Employee e JOIN Employee m ON e.managerId = m.id 
WHERE e.salary > m.salary   

-- @lc code=end

