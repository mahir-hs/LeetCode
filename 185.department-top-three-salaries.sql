--
-- @lc app=leetcode id=185 lang=mysql
--
-- [185] Department Top Three Salaries
--

-- @lc code=start
# Write your MySQL query statement below

SELECT 
    d.name AS Department,e.name AS Employee,e.salary AS Salary 
FROM 
    Employee as e JOIN Department as d ON e.departmentId = d.id
WHERE
    (
        SELECT COUNT(DISTINCT e2.salary) FROM Employee as e2 WHERE e2.salary >= e.salary AND e2.departmentId = e.departmentId
    )
    <= 3
ORDER BY
    d.name,e.salary DESC


