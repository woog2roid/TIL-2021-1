##### https://programmers.co.kr/learn/courses/30/lessons/59039
```
SELECT ANIMAL_ID
FROM ANIMAL_INS
WHERE NAME IS NULL;
```
##### https://programmers.co.kr/learn/courses/30/lessons/59407
```
SELECT ANIMAL_ID
FROM ANIMAL_INS
WHERE NAME IS NOT NULL;
```
##### https://programmers.co.kr/learn/courses/30/lessons/59410
```
SELECT ANIMAL_TYPE,
CASE
WHEN NAME IS NULL THEN "No name"
WHEN NAME IS NOT NULL THEN NAME
END
AS NAME,
SEX_UPON_INTAKE
FROM ANIMAL_INS
ORDER BY ANIMAL_ID;
```