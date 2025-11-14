SELECT a.name AS "Employee"
FROM Employee a
JOIN Employee b
ON a.managerId = b.id
WHERE a.salary > b.salary;