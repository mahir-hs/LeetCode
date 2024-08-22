--
-- @lc app=leetcode id=1327 lang=mysql
--
-- [1327] List the Products Ordered in a Period
--

-- @lc code=start
# Write your MySQL query statement below
SELECT p.product_name AS product_name,SUM(o.unit) AS unit
FROM Products AS p
INNER JOIN Orders AS o
ON p.product_id=o.product_id
WHERE YEAR(o.order_date)=2020 AND MONTH(o.order_date)=2
GROUP BY p.product_name
HAVING SUM(o.unit)>=100
-- @lc code=end

