//
// Created by homsl on 2020/4/27.
//
SELECT tb2.Name AS Department, tb1.Name AS Employee, tb1.Salary
        FROM Employee AS tb1, Department AS tb2
WHERE (SELECT COUNT(DISTINCT Salary)
       FROM Employee AS tb3
       WHERE tb3.DepartmentId = tb1.DepartmentId AND tb3.Salary > tb1.Salary) < 3
AND tb1.DepartmentId = tb2.Id
