# Write your MySQL query statement below
select  unique_id,name
from Employees as emp left join EmployeeUNI as empuni
on emp.id=empuni.id