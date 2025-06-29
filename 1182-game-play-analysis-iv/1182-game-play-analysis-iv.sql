WITH first_login AS (
    SELECT player_id, MIN(event_date) AS first_date
    FROM Activity
    GROUP BY player_id
),
next_day_login AS (
    SELECT f.player_id
    FROM first_login f
    JOIN Activity a 
      ON f.player_id = a.player_id 
     AND a.event_date = DATE_ADD(f.first_date, INTERVAL 1 DAY)
)

SELECT 
    ROUND(COUNT(DISTINCT n.player_id) / COUNT(DISTINCT f.player_id), 2) AS fraction
FROM 
    first_login f
LEFT JOIN 
    next_day_login n ON f.player_id = n.player_id;
