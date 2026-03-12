Question

Table: Customer

Column Name	Type
id	int
name	varchar
referee_id	int

Find the names of customers that are not referred by the customer with id = 2.

Return the result table in any order.

Table Example
id	name	referee_id
1	Will	NULL
2	Jane	NULL
3	Alex	2
4	Bill	NULL
5	Zack	1
6	Mark	2
SQL Solution


SELECT name
FROM Customer
WHERE referee_id != 2
OR referee_id IS NULL;