--
-- @lc app=leetcode id=607 lang=mysql
--
-- [607] Sales Person
--

-- @lc code=start
# Write your MySQL query statement below
SELECT name FROM SalesPerson
WHERE sales_id NOT IN
(
    SELECT sales_id FROM Orders
    WHERE com_id IN
    (
        SELECT com_id FROM Company
        WHERE name = 'RED'
    )
)

-- @lc code=end

