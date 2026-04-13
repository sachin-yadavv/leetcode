SELECT
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary

FROM Department d

JOIN Employee e 

ON d.id = e.departmentId

WHERE
    (
        SELECT COUNT(DISTINCT e2.salary)
        FROM Employee e2
        WHERE e2.departmentId = e.departmentId
          AND e2.salary > e.salary
    ) < 3 
-- Count how many distinct salaries are greater than current salary
-- If that count is less than 3, then it's in top 3
;