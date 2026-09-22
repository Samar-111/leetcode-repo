# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary
From Employee
where salary NOT IN(SELECT MAX(salary) AS SecondHighestSalary from Employee);