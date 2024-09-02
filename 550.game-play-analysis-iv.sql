--
-- @lc app=leetcode id=550 lang=mysql
--
-- [550] Game Play Analysis IV
--

-- @lc code=start
# Write your MySQL query statement below
SELECT 
    ROUND(
        (
            SELECT COUNT(DISTINCT player_id)
            FROM Activity AS a1
            WHERE EXISTS (
                SELECT 1
                FROM Activity AS a2
                WHERE a1.player_id = a2.player_id
                  AND a2.event_date = DATE_ADD(a1.event_date, INTERVAL 1 DAY)
                  AND a1.event_date = (
                      SELECT MIN(event_date)
                      FROM Activity
                      WHERE player_id = a1.player_id
                  )
            )
        ) / (
            SELECT COUNT(DISTINCT player_id)
            FROM Activity
        ), 2
    ) AS fraction

-- @lc code=end

