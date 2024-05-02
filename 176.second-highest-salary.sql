--
-- @lc app=leetcode id=176 lang=mysql
--
-- [176] Second Highest Salary
--

-- @lc code=start
# Write your MySQL query statement below
    SELECT IF( (SELECT COUNT(*) FROM Employee) < 2  ,NULL,(SELECT DISTINCT salary FROM Employee ORDER BY salary DESC LIMIT 1,1)) AS SecondHighestSalary
-- @lc code=end

