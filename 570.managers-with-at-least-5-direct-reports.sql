--
-- @lc app=leetcode id=570 lang=mysql
--
-- [570] Managers with at Least 5 Direct Reports
--

-- @lc code=start
# Write your MySQL query statement below
SELECT 
    e.name 
FROM 
    Employee e
JOIN 
    (SELECT 
        managerId 
     FROM 
        Employee 
     WHERE 
        managerId IS NOT NULL 
     GROUP BY 
        managerId 
     HAVING 
        COUNT(*) >= 5
    ) AS subquery
ON 
    e.id = subquery.managerId;

-- @lc code=end

