SQL 첫걸음 책의 23-24강을 정리한 내용.

### 서브쿼리
```
DELETE FROM sample1
WHERE a = (SELECT min(a) from sample1)
```
과 같이 select문에 의한 데이터 질의이다.

- 상부가 아닌 하부의 부수적인 질의를 의미

보통 일반적으로, where구에서 사용되지만, select나 from, set 에서도 이용가능
- from구에 넣어서 사용할 떄는 LIMIT이 없는 sql server에서 LIMIT을 직접 구현해주는 경우도 있음

#### 스칼라 값
select문을 통해서, 여러 종류 (4종류)의 데이터를 받아올 수 있다.
- 셀이 하나인 데이터
- 행은 하나, 열이 여러개인 데이터
- 열은 하나, 행이 여러개인 데이터
- 행과 열 모두 여러개인 데이터

이것들 중에서 셀이 오직 하나인 데이터를 스칼라 값이라고 한다.
- 추가로, 스칼라 값을 반환하는 서브쿼리를 스칼라 서브쿼리라고 한다.

- =, <>, >과 같은 기본적인 연산자들을 단일 행 비교연산자라고 한다.
	- 단일 행만을 비교할 수 있다는 뜻인데, 이를 이용할 때는 스칼라 값이 필요하다.
- 뒤에나오는 EXISTS, IN등을 다중 행 비교연산자라고 하는데,
	- 이는 =, <>과 같은 단일 행 비교연산자와 "함께"이용이 가능하다.
	- 이를 이용해서 스칼라값이 아닌 서브쿼리 결과를 비교 가능하다.
	
#### INSERT 명령과 서브쿼리
- INSERT SELECT 명령을 통해 SELECT로 얻은 테이블을 그대로 넣을 수 있다.
	- 물론 그 형식이 insert명령의 대상의 형식과 맞아야 한다.
	
### 상관 서브쿼리
- 상관 서브쿼리는 부모 명령과 연관되어 있기 떄문에 서브쿼리 부분만 따로 떼어내는 것이 불가능하다
```
상관 서브쿼리
UPDATE smpale1 SET a="있음" WHERE
EXISTS (SELECT * FROM sample2 WHERE no = no2)
```
- no은 sample1의 no이고, no2는 sample2의 no이다.
- 서브쿼리만 잘라서 실행하면 절대 실행이 될리가 없다.

#### 열에 테이블명 붙이기
위와 같은 경우는, 둘다 idNO를 no으로 지정하고,  
```
"WHERE sample1.no = smpale2.no"
```
와 같이 다른 언어들처럼 쓸수 있다.

### EXISTS와 IN
[여기](https://doorbw.tistory.com/222)를 참고해보자

#### EXISTS
```
UPDATE smpale1 SET a="있음" WHERE
EXISTS (SELECT * FROM sample2 WHERE no = no2)
```
를 입력하면, sample2의 no2와 sample1의 no가 같은 모든 sample1 행의
a가 있음으로 바뀐다.

- NOT EXISTS의 경우에는 EXISTS와 반대로 작동한다.

#### IN
```
SELECT * FROM sample1 WHERE no IN (3,5);

SELECT * FROM sampel1 WHERE no IN
	(SELECT no2 FROM smpale2)
```
를 입력하면, 위에서는 no가 3,5 중 하나인 행이 출력된다.
- where문에서 or를 여러번 입력할 필요가 없다는 뜻
- 두 번째 쿼리문과 같이 IN은 집합을 받기 떄문에 테이블을 넘겨주어도 된다.

- NOT IN은 IN과 반대.