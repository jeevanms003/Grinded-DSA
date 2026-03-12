Question

Table: World

Column Name	Type
name	varchar
continent	varchar
area	int
population	int
gdp	bigint

A country is big if:

it has an area ≥ 3,000,000
OR

a population ≥ 25,000,000

Write a solution to find the name, population, and area of big countries.

Table Example
name	continent	area	population	gdp
Afghanistan	Asia	652230	25500100	20343000000
Albania	Europe	28748	2831741	12960000000
Algeria	Africa	2381741	37100000	188681000000
SQL Solution


SELECT name, population, area
FROM World
WHERE area >= 3000000
OR population >= 25000000;