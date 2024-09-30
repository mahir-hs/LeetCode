--
-- @lc app=leetcode id=1158 lang=mysql
--
-- [1158] Market Analysis I
--

-- @lc code=start
# Write your MySQL query statement below
SELECT u.user_id AS buyer_id,u.join_date AS join_date,COUNT(o.order_date) AS orders_in_2019
FROM Users u LEFT JOIN Orders o 
ON u.user_id=o.buyer_id
AND YEAR(o.order_date)=2019
GROUP BY u.user_id
-- @lc code=end

