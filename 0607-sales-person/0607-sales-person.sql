# Write your MySQL query statement below
SELECT s.name 
from SalesPerson s 
where s.name not in(
                    SELECT s.name 
                    FROM
                    SalesPerson s 
                    LEFT JOIN Orders O
                    ON s.sales_id=O.sales_id
                    LEFT JOIN Company C
                    ON O.com_id=C.com_id
                    WHERE C.name='RED'
                )