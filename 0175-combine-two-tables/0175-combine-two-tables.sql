/* Write your PL/SQL query statement below */
select a.firstName, a.lastName, b.city, b.state
from Person a, Address b
where a.personId = b.personId(+)