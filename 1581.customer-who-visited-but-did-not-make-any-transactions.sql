--
-- @lc app=leetcode id=1581 lang=mysql
--
-- [1581] Customer Who Visited but Did Not Make Any Transactions
--

-- @lc code=start
# Write your MySQL query statement below

SELECT a.customer_id as customer_id, COUNT(a.customer_id) as count_no_trans  FROM Visits as a LEFT JOIN Transactions as b ON  a.visit_id=b.visit_id WHERE b.transaction_id IS NULL GROUP BY a.customer_id

-- @lc code=end

