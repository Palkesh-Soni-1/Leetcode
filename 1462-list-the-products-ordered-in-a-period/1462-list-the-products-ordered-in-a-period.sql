# Write your MySQL query statement below

select product_name, unit
from products as p
join (
select product_id, sum(unit) as unit
from orders
where order_date like '2020-02-__'
group by product_id
) as o
on p.product_id = o.product_id
where unit>=100;