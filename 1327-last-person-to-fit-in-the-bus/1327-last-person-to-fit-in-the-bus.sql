select person_name
from queue
where turn = (
    SELECT count(*)
FROM (
    SELECT *,
           SUM(weight) OVER (ORDER BY turn) AS running_weight
    FROM queue
) q
WHERE running_weight <= 1000
ORDER BY turn
)
order by turn;
