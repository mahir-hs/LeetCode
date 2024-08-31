--
-- @lc app=leetcode id=1407 lang=mysql
--
-- [1407] Top Travellers
--

-- @lc code=start
# Write your MySQL query statement below
SELECT x.name AS name, SUM(CASE WHEN y.distance IS NULL THEN 0 ELSE y.distance END) AS  travelled_distance
FROM 
    Users AS x LEFT JOIN Rides AS y
ON 
    x.id=y.user_id
GROUP BY 
    x.id
ORDER BY 
    travelled_distance DESC,x.name ASC
-- @lc code=end

