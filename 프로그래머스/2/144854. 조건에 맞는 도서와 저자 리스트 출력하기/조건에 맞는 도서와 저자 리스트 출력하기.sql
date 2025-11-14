-- 코드를 입력하세요
SELECT 
    BOOK_ID,
    AUTHOR_NAME,
    TO_CHAR(PUBLISHED_DATE, 'YYYY-MM-DD') AS published_date
FROM (
    SELECT *
    FROM BOOK
    WHERE CATEGORY = '경제'
) b
JOIN AUTHOR a
ON b.AUTHOR_ID = a.AUTHOR_ID
ORDER BY published_date;