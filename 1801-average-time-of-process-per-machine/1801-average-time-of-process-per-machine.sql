# Write your MySQL query statement below
select a1.machine_id, Round(Avg(a2.timestamp - a1.timestamp),3) as processing_time 
from activity as a1 left join activity as a2 
on (a1.machine_id, a1.process_id, a1.activity_type="start")=(a2.machine_id, a2.process_id, a2.activity_type="end") 
where a1.activity_type='start' 
Group by machine_id;