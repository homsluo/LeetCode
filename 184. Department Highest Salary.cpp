//
// Created by homsl on 2020/4/27.
//

SELECT tb2.Name AS Department, tb1.Name AS Employee, tb1.Salary As Salary
        FROM Employee AS tb1, Department AS tb2,
(SELECT DepartmentId, MAX(Salary) AS Maxsalary
FROM Employee
GROUP BY DepartmentId) AS tb3
WHERE tb1.DepartmentId = tb2.Id AND
        tb1.Salary = tb3.Maxsalary AND
        tb1.DepartmentId = tb3.DepartmentId