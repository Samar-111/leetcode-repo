# Write your MySQL query statement below
SELECT d.name AS Department,e.name AS Employee,e.salary AS Salary
FROM Employee e
JOIN Department d ON e.departmentId=d.Id
WHERE e.Salary=(SELECT MAX(salary) FROM Employee WHERE departmentId=e.departmentId);
