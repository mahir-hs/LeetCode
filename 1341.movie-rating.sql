--
-- @lc app=leetcode id=1341 lang=mysql
--
-- [1341] Movie Rating
--

-- @lc code=start
# Write your MySQL query statement below
SELECT 
    name AS results
FROM (
    SELECT 
        u.name,
        COUNT(DISTINCT mr.movie_id) AS movie_count
    FROM 
        Users u
    JOIN 
        MovieRating mr ON u.user_id = mr.user_id
    GROUP BY 
        u.user_id, u.name
    ORDER BY 
        movie_count DESC, u.name
    LIMIT 1
) AS top_user
UNION ALL
SELECT 
    title AS results
FROM (
    SELECT 
        m.title,
        AVG(mr.rating) AS avg_rating
    FROM 
        Movies m
    JOIN 
        MovieRating mr ON m.movie_id = mr.movie_id
    WHERE 
        mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY 
        m.movie_id, m.title
    ORDER BY 
        avg_rating DESC, m.title
    LIMIT 1
) AS top_movie;


-- @lc code=end

