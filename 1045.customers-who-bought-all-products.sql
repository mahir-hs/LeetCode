--
-- @lc app=leetcode id=1045 lang=mysql
--
-- [1045] Customers Who Bought All Products
--

-- @lc code=start
# Write your MySQL query statement below

SELECT customer_id
FROM Customer
JOIN Product ON Customer.product_key = Product.product_key
GROUP BY customer_id
HAVING COUNT(DISTINCT Product.product_key) = (SELECT COUNT(DISTINCT product_key) FROM Product);


-- @lc code=end

