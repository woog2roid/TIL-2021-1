##### https://programmers.co.kr/learn/courses/30/lessons/59040
```
SELECT ANIMAL_TYPE, COUNT(ANIMAL_ID) AS count
FROM ANIMAL_INS
WHERE ANIMAL_TYPE="Cat" OR ANIMAL_TYPE="Dog"
GROUP BY ANIMAL_TYPE
ORDER BY ANIMAL_TYPE;
```

##### https://programmers.co.kr/learn/courses/30/lessons/59041
```
SELECT NAME, COUNT(ANIMAL_ID) AS "COUNT"
FROM ANIMAL_INS
GROUP BY NAME
HAVING COUNT(NAME) > 1
ORDER BY NAME;
```

##### https://programmers.co.kr/learn/courses/30/lessons/59412
```
SELECT HOUR(DATETIME) AS HOUR, COUNT(ANIMAL_ID) AS COUNT
FROM ANIMAL_OUTS
WHERE HOUR(DATETIME) >=9 AND HOUR(DATETIME) <= 19
GROUP BY HOUR(DATETIME)
ORDER BY HOUR(DATETIME);
```

- DATETIME 형식을 HOUR로 감싸면 시간이 나온다...
##### https://programmers.co.kr/learn/courses/30/lessons/59413
```
SET @hour = -1;

SELECT @hour := @hour +1 AS HOUR,
(SELECT COUNT(*) FROM ANIMAL_OUTS WHERE @hour = HOUR(DATETIME))
FROM ANIMAL_OUTS
WHERE @hour < 23;
```
- 변수 지정해서 푸는 문제, 변수 지정은 그냥 있다고만 알고있었고 한번도 해본적 없었는데,
	- "SET @변수 = 값"을 통해 변수를 초기화 시킬 수 있음,
	- SET 문이 아닌 곳에서는 =은 비교연산자로 이용되기 때문에 :=을 이용해야만,
	- "대입"연산을 할 수 있다.

- 서브쿼리와 변수를 둘다 이용해야만 풀렸다.