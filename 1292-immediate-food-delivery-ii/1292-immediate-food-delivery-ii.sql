WITH min_orders AS (
    SELECT customer_id, MIN(order_date) AS min_order_date
    FROM delivery
    GROUP BY customer_id
),
temp AS (
    SELECT 
        d.customer_id,
        MIN(d.order_date) AS first_order_date,
        COUNT(
            CASE 
                WHEN d.order_date = m.min_order_date 
                     AND d.customer_pref_delivery_date = m.min_order_date 
                THEN 1 
                ELSE NULL
            END
        ) AS matched_count
    FROM 
        delivery d
    JOIN 
        min_orders m ON d.customer_id = m.customer_id
    GROUP BY 
        d.customer_id
)

SELECT ROUND(AVG(matched_count) * 100, 2) AS immediate_percentage
FROM temp;
