Question

Table: Products

Column Name	Type
product_id	int
low_fats	enum
recyclable	enum

low_fats is 'Y' if the product is low fat.
recyclable is 'Y' if the product is recyclable.

Write a solution to find the ids of products that are both low fat and recyclable.

Return the result table in any order.

Table Example
product_id	low_fats	recyclable
0	Y	N
1	Y	Y
2	N	Y
3	Y	Y
4	N	N
SQL Solution


SELECT product_id
FROM Products
WHERE low_fats = 'Y'
AND recyclable = 'Y';