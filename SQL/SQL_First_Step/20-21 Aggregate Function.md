SQL 첫걸음 책의 20강~21강을 정리한 내용.

### 집계 함수
- 집합을 다루는 함수
	- 일반적인 함수는 인수(parameter)로 하나의 값을 지정, 집계함수는 "집합"을 지정함
	- 하나의 집합에서 "하나의 값"을 반환함

### COUNT 함수
__SELECT COUNT( * ) FROM sample WHERE name = 'A'__

- 이름이 A인 행을 모두 세어서 반환

결과값 (2개가 있다고 가정.)
```
COUNT(*)
--------
2
```
- _집계함수에서 NULL값은 무시하고 처리한다._

#### DISTINCT
- DISTINCT를 통해 중복된 값을 제거할 수 있다.
	- SELECT DISTINCT name FROM sample
	- SELECT COUNT (DISTINCT name) FROM sample
	
COUNT안에 DISTINCT를 쓴 이유?  
COUNT가 SELECT보다 먼저 계산되므로, SELECT에 DISTINCT를 붙여도 의미 없음.
- 추가로, DISTINCT가 없으면, ALL로 자동으로 값이 지정된다.

### SUM AVG MIN MAX
SELECT SUM(price) FROM sample;  
SELECT AVG(height) FROM sample;  
SELECT MIN(weight) FROM sample;  
SELECT MAX(weight) FROM sample;  

과 같이 쓸 수 있으며,  
NULL은 무시하므로, AVG를 계산할 때 NULL을 포함하고 싶으면,  
CASE문으로 NULL을 0으로 바꾸고 계산해야 한다.
