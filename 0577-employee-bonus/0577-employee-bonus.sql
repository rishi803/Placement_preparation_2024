# Write your MySQL query statement below
select Emp.name, Bonus.bonus
from Employee as Emp left join Bonus
on Emp.empId=Bonus.empId
where bonus<1000 or bonus is null