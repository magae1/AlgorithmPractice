SELECT (
    SELECT salary
    FROM (
        SELECT salary,
               DENSE_RANK() OVER (ORDER BY salary DESC) rk
        FROM Employee
    )
    WHERE rk = 2 AND ROWNUM = 1
) AS "SecondHighestSalary"
FROM dual;
