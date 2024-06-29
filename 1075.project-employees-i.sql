--
-- @lc app=leetcode id=1075 lang=mysql
--
-- [1075] Project Employees I
--

-- @lc code=start
# Write your MySQL query statement below
SELECT p.project_id AS project_id, ROUND(SUM(e.experience_years)/COUNT(*),2) AS average_years
FROM Project p JOIN Employee e 
WHERE p.employee_id=e.employee_id
GROUP BY project_id


-- @lc code=end

