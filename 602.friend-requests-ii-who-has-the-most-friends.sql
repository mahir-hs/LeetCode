--
-- @lc app=leetcode id=602 lang=mysql
--
-- [602] Friend Requests II: Who Has the Most Friends
--

-- @lc code=start
# Write your MySQL query statement below

WITH ac as(
    SELECT requester_id AS id,COUNT(accepter_id) AS num
    FROM RequestAccepted
    GROUP BY requester_id

    UNION ALL

    SELECT accepter_id  AS id ,COUNT(requester_id) AS num
    FROM RequestAccepted
    GROUP BY accepter_id
)

SELECT id,SUM(num) AS num
FROM ac
GROUP BY id
ORDER BY num DESC
LIMIT 1


-- @lc code=end

