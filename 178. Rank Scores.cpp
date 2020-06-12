//
// Created by homsl on 2020/4/25.
//
# Write your MySQL query statement below

# Window Function:
# FUNCTION() OVER(PARTITION BY x, ORDER BY y, ASC/DESC)
# RANK():same value different rank, ROW_NUMBER(): non consecutive rank, DENSE_RANK()
# But Window Function can not use in MySQL

SELECT tb1.Score as Score, (SELECT COUNT(DISTINCT tb2.Score)
FROM Scores as tb2
WHERE tb2.Score > tb1.Score) + 1 AS Rank
FROM Scores as tb1
ORDER BY Score DESC
