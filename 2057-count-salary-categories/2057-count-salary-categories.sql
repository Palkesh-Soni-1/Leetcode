SELECT category, COUNT(a.account_id) AS accounts_count
FROM (
    SELECT 'Low Salary' AS category
    UNION ALL
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'
) AS categories
LEFT JOIN accounts a
ON (
    (categories.category = 'Low Salary' AND a.income < 20000) OR
    (categories.category = 'Average Salary' AND a.income BETWEEN 20000 AND 50000) OR
    (categories.category = 'High Salary' AND a.income > 50000)
)
GROUP BY category;
