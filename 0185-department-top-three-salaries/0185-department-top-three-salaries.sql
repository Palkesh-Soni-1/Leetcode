# Write your MySQL query statement below
select d.name as Department ,eo.name as Employee , salary  as Salary
from Employee eo inner join Department d 
on d.id=eo.departmentId
where 3 >(select count( distinct salary) from Employee ei where ei.departmentId=eo.departmentId and eo.salary <ei.salary )