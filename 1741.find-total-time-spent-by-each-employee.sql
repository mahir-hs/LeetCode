--
-- @lc app=leetcode id=1741 lang=mysql
--
-- [1741] Find Total Time Spent by Each Employee
--

-- @lc code=start
# Write your MySQL query statement below
SELECT event_day as day,emp_id, SUM(out_time-in_time) as total_time FROM Employees
GROUP BY event_day,emp_id
-- @lc code=end

