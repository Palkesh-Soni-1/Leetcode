# Write your MySQL query statement below

select p.product_id, coalesce(new_price,10) as price
from (select distinct product_id from products) as p
left join
(
select p.product_id, new_price
from products as p
join 
(select product_id, max(change_date) as d 
from products
where change_date<='2019-08-16'
group by product_id
) as t
on p.product_id = t.product_id and p.change_date = t.d
) as f
on p.product_id = f.product_id;





