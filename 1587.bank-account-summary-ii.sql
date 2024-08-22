--
-- @lc app=leetcode id=1587 lang=mysql
--
-- [1587] Bank Account Summary II
--

-- @lc code=start
# Write your MySQL query statement below

SELECT u.name as name,SUM(t.amount) as balance 
FROM Users as u JOIN Transactions as t
WHERE u.account=t.account 
GROUP BY u.name
HAVING SUM(t.amount)>10000
-- @lc code=end

