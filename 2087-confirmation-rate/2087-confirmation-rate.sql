# Write your MySQL query statement below
-- select s.user_id,count(c.user_id)
-- from signups as s left join confirmations as c on s.user_id=c.user_id
-- group by s.user_id;

-- select count(c.user_id)
-- from signups as s left join confirmations as c on s.user_id=c.user_id and c.action = "confirmed"
-- group by s.user_id;

SELECT 
    s.user_id,
    Round(
    CASE 
        WHEN COUNT(c.action) = 0 THEN 0
        ELSE COUNT(CASE WHEN c.action = 'confirmed' THEN 1 END) * 1.0 / COUNT(c.action)
    END,2) AS confirmation_rate
FROM 
    signups s
LEFT JOIN 
    confirmations c ON s.user_id = c.user_id
GROUP BY 
    s.user_id;

