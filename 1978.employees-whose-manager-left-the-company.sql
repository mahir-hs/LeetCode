--
-- @lc app=leetcode id=1978 lang=mysql
--
-- [1978] Employees Whose Manager Left the Company
--

-- @lc code=start
# Write your MySQL query statement below
SELECT e.employee_id
FROM Employees e
WHERE e.salary < 30000
  AND e.manager_id IS NOT NULL
  AND e.manager_id NOT IN (
      SELECT employee_id
      FROM Employees
  )
ORDER BY e.employee_id;


-- @lc code=end

