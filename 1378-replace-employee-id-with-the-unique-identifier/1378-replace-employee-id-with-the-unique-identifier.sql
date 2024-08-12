# Write your MySQL query statement below
SELECT empU.unique_id, emp.name
FROM Employees as emp
LEFT JOIN EmployeeUNI as empU
ON emp.id = empU.id;