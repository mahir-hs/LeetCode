--
-- @lc app=leetcode id=177 lang=mysql
--
-- [177] Nth Highest Salary
--

-- @lc code=start
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N-1;
  RETURN (
     
          (SELECT DISTINCT salary
           FROM Employee
           ORDER BY salary DESC
           LIMIT 1 OFFSET N)

  );
END
-- @lc code=end

