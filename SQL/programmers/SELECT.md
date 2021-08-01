##### https://programmers.co.kr/learn/courses/30/lessons/59034
```
SELECT * FROM ANIMAL_INS ORDER BY ANIMAL_ID;
```
##### https://programmers.co.kr/learn/courses/30/lessons/59035
```
SELECT NAME, DATETIME FROM ANIMAL_INS ORDER BY ANIMAL_ID DESC;
```
##### https://programmers.co.kr/learn/courses/30/lessons/59036#fn1
```
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE INTAKE_CONDITION="Sick"
ORDER BY ANIMAL_ID;
```
##### https://programmers.co.kr/learn/courses/30/lessons/59037
```
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE INTAKE_CONDITION <> "Aged"
ORDER BY ANIMAL_ID;
```
##### https://programmers.co.kr/learn/courses/30/lessons/59403
```
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
ORDER BY ANIMAL_ID;
```
##### https://programmers.co.kr/learn/courses/30/lessons/59404
```
SELECT ANIMAL_ID, NAME, DATETIME
FROM ANIMAL_INS
ORDER BY NAME, DATETIME DESC;
```
##### https://programmers.co.kr/learn/courses/30/lessons/59405
```
SELECT NAME
FROM ANIMAL_INS
ORDER BY DATETIME
LIMIT 1;
```