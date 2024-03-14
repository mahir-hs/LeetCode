--
-- @lc app=leetcode id=1378 lang=mysql
--
-- [1378] Replace Employee ID With The Unique Identifier
--

-- @lc code=start
# Write your MySQL query statement below
SELECT b.unique_id as unique_id, a.name as name FROM Employees a LEFT JOIN EmployeeUNI b ON a.id=b.id
-- @lc code=end

