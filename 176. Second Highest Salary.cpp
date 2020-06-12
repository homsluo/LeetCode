//
// Created by homsl on 2020/4/16.
//
select max(t1.salary) as secondhighestsalary
from (
        select salary
        from employee
        where salary < (
select max(salary)
from employee)) as t1

//

select max(salary) as secondhighestsalary
from employee
where salary < (
        select max(salary)
from employee)
