# Write your MySQL query statement below
select query_name,
round(avg(rating/position),2) as quality,
round((count(CASE WHEN q.rating < 3 THEN 1 END)*1.0 /count(query_name))*100,2) as poor_query_percentage
from queries as q
group by query_name; 


-- (select count(rating) from queries group by query_name having rating<3)