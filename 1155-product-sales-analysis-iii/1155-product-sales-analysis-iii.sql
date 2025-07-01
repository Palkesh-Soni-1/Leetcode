# Write your MySQL query statement below
select s.product_id, s.year as first_year, s.quantity, s.price
from sales as s
join (
    select product_id, min(year) as first_year
    from sales
    group by product_id
) as first_sales
on s.product_id=first_sales.product_id and s.year = first_sales.first_year;
