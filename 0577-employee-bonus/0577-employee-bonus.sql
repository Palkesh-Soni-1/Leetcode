# Write your MySQL query statement below
select name,bonus from employee as e left join bonus as b on e.empId = b.empId where bonus<1000 Or bonus Is null;