SQL 첫걸음 책의 12강~15강을 정리한 내용.

### 수치연산
_연산자의 우선순위와 연산자 기호는 생략_

__"SELECT *, price * quantity AS amount FROM sample34;"__

|no|price|quantity|amount|
|---|---|---|---|
|1|100|10|1000|
|2|230|24|5520|
|3|1980|1|1980|

- SELECT 구에 * 를 입력하고 ,를 입력하고 price * quantity를 입력했음
	- 모든 열을 나열 + price * quantity라는 열도 추가해서 나열 (물론 계산도 ㅇㅇ)
	- AS 라는 예약어를 사용해서 price * quantity의 별명(alias)를 amount로 지어줬음
		- AS가 없었으면, price * quantity가 열의 이름이었음.
		- AS는 생략가능함
		- 별명을 아스키문자 외에 것을 포함시켜서 지으려면 "가 필요하다.
		- 최대한 숫자로 시작하지 않는 것이 좋으며, "를 이용하면 예약어와 겹치는 이름도 사용이 가능은 하다...

__"SELECT *, price * quantity AS amount FROM sample34 WHERE amount >= 2000;"__
- 에러: amount라는 열은 존재하지 않는다?
	- 서버에서 WHERE부터 돌리고 SELECT를 돌리기 때문에 amount는 존재하지 않는다.
__"SELECT *, price * quantity AS amount FROM sample34 ORDER BY amount ASC;"__
- 잘 실행됨
	- 서버에서는 WHERE -> SELECT -> ORDER 순으로 실행되기 떄문
	
_참고사항_
1. NULL은 연산을 해도 NULL이 나온다.
2. 함수들 ROUND, SIN과 같은 함수들도 제공해준다.
	- SELECT amount, ROUND(amount, -2) FROM sample2;와 같이 작성하면 10단위를 반올림한다.

### 문자열 연산
1. 문자열 결합
	- 데이터 베이스 제품마다 방언이 있으며, +, ||, CONCAT등으로 결합한다.
2. SUBSTRING(SUBSTR)함수
	- 특정 문자열만 뽑아서 반환해주는 함수
3. TRIM 함수
	- 문자열의 앞뒤로 여분의 스페이스를 제거함, 문자열 내의 스페이스는 제거하지 않는다.
4. CHARACTER_LENGTH
	- 문자열의 길이를 계산해 돌려준다
	- OCTET_LENGTH(문자열의 길이를 바이트 단위로 계산)의 경우에는 문자열 세트(EUC-KR, UTF-8)에 따라 크기가 달라질 수 있다.
	
### 날짜 연산
__"CURRENT_TIMESTAMP CURRENT_DATE INTERVAL"__
- CURRENT_TIMESTAMP: 시스템 시각 확인 
	- SELECT CURRENT_TIMESTAMP;  --> (2014-01-25 10:10:30)
- CURRENT_DATE: 시스텔 날짜
- interval: 기간형(1일, 시간간의 간격) 데이터

### CASE문으로 데이터 변환하기
__"SELECT a,  
CASE  
WHEN a IS NULL THEN 0  
ELSE a  
END  
"a(null=0)"  
FROM sample1;__
- a열과 a(null=0)을 내보내라.
	- AS가 생략되었음
	- a(null=0)열은 CASE문을 통해 NULL이면 0을 출력하고 아니면 a를 그대로 출력하는 열
	- ELSE문이 마지막에 없으면 기본으로 ELSE NULL이 들어간다.

- __단순 CASE문 vs 검색 CASE문__
- 단순 CASE문
```
	CASE a
	WHEN 1 THEN '남자'
	WHEN 2 THEN '여자'
	ELSE '미지정'
	END
```
와 같이, CASE 뒤에 기준이 되는 변수를 두고 검색하는 것.  
(switch문 생각하면 된다.)  

- 검색 CASE문
	- IS NULL로 NULL을 비교하기 위해 필요하다...
```
	CASE
	WHEN a = 1 THEN '남자'
	WHEN a = 2 THEN '여자'
	WHEN a IS NULL THEN '데이터 없음'
	ELSE '미지정'
	END
```
(IF ELSE IF 생각하면 된다.)