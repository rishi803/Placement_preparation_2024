# Write your MySQL query statement below

 # using left join (left join joins two table and for primary key of table 1 is not in table 2 show null )
 
# select  empuni.unique_id,emp.name
# from Employees as emp left join EmployeeUNI as empuni
# on emp.id=empuni.id

# using right join (replace table1 as table2 and vice versa)
select  empuni.unique_id,emp.name
from  EmployeeUNI as empuni right join Employees as emp
on empuni.id=emp.id
