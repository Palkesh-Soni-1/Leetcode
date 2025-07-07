# Write your MySQL query statement below
-- select name
-- from (
--     select u.user_id, name, count(user_id)
--     from movierating as m join users as u
--     on m.user_id = u.users_id
--     group by m.user_id
-- )



-- select name
-- from movierating as m join users as u
-- on m.user_id = u.user_id
-- group by m.user_id
-- order by count(m.user_id) DESC, name
-- Limit 1;



-- select title, avg(mr.rating)
-- from movies as m
-- join movieRating as mr
-- on m.movie_id = mr.movie_id and mr.created_at LIKE '2020-02-__'
-- group by mr.movie_id
-- order by avg(mr.rating) desc, title
-- limit 1;




select name as results 
from(
select name
from movierating as m join users as u
on m.user_id = u.user_id
group by m.user_id
order by count(m.user_id) DESC, name
Limit 1
) as u

union all

select title as results
from(
select title
from movies as m
join movieRating as mr
on m.movie_id = mr.movie_id and mr.created_at LIKE '2020-02-__'
group by mr.movie_id
order by avg(mr.rating) desc, title
limit 1
) as m
