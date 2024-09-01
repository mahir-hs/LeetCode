--
-- @lc app=leetcode id=626 lang=mysql
--
-- [626] Exchange Seats
--

-- @lc code=start
# Write your MySQL query statement below
SELECT 
    CASE
        WHEN MOD(id,2)=0 THEN id-1
        WHEN MOD(id,2)!=0 AND id!=(SELECT MAX(id) FROM Seat) THEN id+1
        ELSE
            id
    END AS id,
    student
FROM 
    Seat
ORDER BY
    id
-- @lc code=end

