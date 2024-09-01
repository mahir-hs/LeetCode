--
-- @lc app=leetcode id=1204 lang=mysql
--
-- [1204] Last Person to Fit in the Bus
--

-- @lc code=start
# Write your MySQL query statement below
SELECT person_name
FROM (
    SELECT 
        person_name,turn,SUM(weight) OVER (ORDER BY turn) AS cumulative_weight
    FROM Queue
) AS q
WHERE cumulative_weight<=1000
ORDER BY turn DESC 
LIMIT 1

-- @lc code=end

