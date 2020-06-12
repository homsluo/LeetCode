//
// Created by homsl on 2020/4/16.
//
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
        DECLARE m INT;
SET m = N - 1;
RETURN (
# Write your MySQL query statement below.
        SELECT Salary
        FROM Employee
        GROUP BY Salary
ORDER BY Salary DESC
LIMIT m, 1
);
END
