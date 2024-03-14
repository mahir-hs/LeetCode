--
-- @lc app=leetcode id=1068 lang=mysql
--
-- [1068] Product Sales Analysis I
--

-- @lc code=start
# Write your MySQL query statement below
SELECT b.product_name as product_name, a.year as year, a.price as price FROM Product AS b RIGHT JOIN Sales AS a ON b.product_id = a.product_id
-- @lc code=end

