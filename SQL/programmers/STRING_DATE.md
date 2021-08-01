##### https://programmers.co.kr/learn/courses/30/lessons/59046
```
SELECT ANIMAL_ID, NAME, SEX_UPON_INTAKE
FROM ANIMAL_INS
WHERE NAME IN ("Lucy", "Ella", "Pickle", "Rogan", "Sabrina", "Mitty")
ORDER BY ANIMAL_ID;
```
##### https://programmers.co.kr/learn/courses/30/lessons/59047
```
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE NAME LIKE "%EL%" AND ANIMAL_TYPE = "Dog"
ORDER BY NAME;
```
##### https://programmers.co.kr/learn/courses/30/lessons/59409
```
SELECT ANIMAL_ID, NAME, 
CASE 
WHEN SEX_UPON_INTAKE LIKE "%Neutered%" OR SEX_UPON_INTAKE LIKE "%Spayed%" THEN "O"
ELSE "X"
END
AS 중성화
FROM ANIMAL_INS
ORDER BY ANIMAL_ID;
```
##### https://programmers.co.kr/learn/courses/30/lessons/59411
```
SELECT INS.ANIMAL_ID AS ANIMAL_ID, INS.NAME AS NAME
FROM ANIMAL_OUTS AS OUTS JOIN ANIMAL_INS AS INS
ON OUTS.ANIMAL_ID = INS.ANIMAL_ID
ORDER BY OUTS.DATETIME - INS.DATETIME DESC
LIMIT 2;
```
##### https://programmers.co.kr/learn/courses/30/lessons/59414
```
SELECT ANIMAL_ID, NAME, DATE_FORMAT(DATETIME, '%Y-%m-%d') AS 날짜
FROM ANIMAL_INS
ORDER BY ANIMAL_ID;
```