//
// Created by homsl on 2020/4/26.
//
# Write your MySQL query statement below
SELECT tb1.Name as Employee
        FROM Employee as tb1, Employee as tb2
        WHERE tb1.Salary > tb2.Salary AND tb1.ManagerId = tb2.Id
