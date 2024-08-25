--
-- @lc app=leetcode id=1661 lang=mysql
--
-- [1661] Average Time of Process per Machine
--

-- @lc code=start
# Write your MySQL query statement below
SELECT machine_id, ROUND(AVG(end_time-start_time),3) AS processing_time
FROM (
    SELECT machine_id,process_id,
    MAX(CASE WHEN activity_type="end" THEN timestamp ELSE NULL END) AS end_time,
    MAX(CASE WHEN activity_type="start" THEN timestamp ELSE NULL END) AS start_time
    FROM Activity
    GROUP BY machine_id,process_id
) AS X
GROUP BY machine_id
-- @lc code=end

