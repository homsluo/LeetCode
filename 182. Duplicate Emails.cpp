//
// Created by homsl on 2020/4/26.
//
# Write your MySQL query statement below
SELECT DISTINCT tb1.Email
        FROM Person AS tb1, Person AS tb2
        WHERE tb1.Email = tb2.Email AND tb1.Id != tb2.Id
