# Write your MySQL query statement below
SELECT name, population, area
FROM World
having (area>=3000000 or population>=25000000)