--
-- @lc app=leetcode id=175 lang=mysql
--
-- [175] Combine Two Tables
--

-- @lc code=start
# Write your MySQL query statement below
   SELECT firstname,lastname,city,state FROM Person LEFT JOIN Address ON Person.personId = Address.personId
-- @lc code=end

