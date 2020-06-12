//
// Created by homsl on 2020/4/15.
//
# Write your MySQL query statement below
select t1.FirstName, t1.LastName, t2.CIty, t2.State
        from Person as t1 left join Address as t2
on t1.PersonId = t2.PersonId
