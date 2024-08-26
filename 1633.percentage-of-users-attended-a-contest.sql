--
-- @lc app=leetcode id=1633 lang=mysql
--
-- [1633] Percentage of Users Attended a Contest
--

-- @lc code=start
# Write your MySQL query statement below
SELECT r.contest_id AS contest_id,ROUND((COUNT(DISTINCT r.user_id)/(SELECT COUNT(*) FROM Users))*100,2) AS percentage
FROM Register r
GROUP BY r.contest_id
ORDER BY percentage DESC,r.contest_id ASC
-- @lc code=end

