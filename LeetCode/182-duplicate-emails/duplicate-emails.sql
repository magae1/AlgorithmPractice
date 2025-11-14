SELECT DISTINCT email AS Email
FROM Person a
WHERE EXISTS (
    SELECT 1 
    FROM Person b 
    WHERE a.id != b.id AND a.email = b.email
);