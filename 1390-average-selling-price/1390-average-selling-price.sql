# Write your MySQL query statement below
select p.product_id, 
round(
    case
       when count(u.product_id)=0 then 0
       else sum(price*units)/sum(units)
    end,
    2)
    as average_price
from prices as p
left join 
unitssold as u 
on p.product_id=u.product_id 
and u.purchase_date between start_date and end_date
group by p.product_id;