SQL 첫걸음 책의 25-30강을 정리한 내용.

### 데이터베이스 객체
데이터 베이스 내의 객체라는 뜻
- 객체: 어떠한 실체를 가지는 것 (ex: 테이블은 객체, 명령은 객체가 아님)
- 객체의 이름은 중복될 수 없다.

스키마
- 데이터 베이스가 만들어지는 그릇
- "CREATE DATABASE 이름"으로 만들어진 DB가 스키마임
	- SNAKE ONLINE할 때 이 CREATE DATABASE는 한번만 했던거 기억하지...?
- 데이터베이스 객체를 스키마 객차라고 부르기도 함

테이블과 스키마는 네임스페이스이다.
- 네임스페이스: 이름이 충동하지 않도록 기능하는 그릇, C++의 그것 맞음
	- 여러 테이블에 ID라는 열이 있어도 상관없듯이
	
### 테이블의 작성 삭제 변경
테이블 만들기
```
CREATE TABLE 테이블명 
(no INTEGER NOT NULL UNIQUE
a VARCHAR(30)
b DATE);
```

테이블 삭제
```
DROP TABLE 테이블명
```
- 테이블 형태는 남기고 싶으면 DELETE * FROM 테이블로 지울 수 있다.
	- WHERE문을 안채우면....
- TRUNCATE TABLE 테이블명 명령도 지원해준다.

테이블 변경
```
ALTER TABLE 테이블명 하부명령

ALTER TABLE 테이블명 ADD newcol INTEGER
ALTER TABLE 테이블명 MODIFY (
	newcol VARACHAR(20) UNIQUE
)
ALTER TABLE 테이블명 CHANGE newcol col
ALTER TABLE 테이블명 DROP col
```
- 새로운 열 추가, 열 제약 바꾸기, 열 이름 바꾸기, 열 삭제

### 제약
열 제약과 테이블 제약
- 열제약: NOT NULL, UNIQUE와 같이 열에 거는 제약
	- CREATE TABLE에서 열 명 옆에 작성
- 테이블제약: PRIMARY KEY와 같이 테이블에 거는 제약
	- CREATE TABLE에서 맨 밑에 작성
	
PRIMARY KEY
```
CREATE TABLE sample (
id INTEGER NOT NULL,
name VARCHAR(30) NOT NULL,
PRIMARY KEY (id)

CONSTRAINT pkey PRIMARY KEY (id)
)
```
- constraint로 제약 이름을 정할 수 있다.
	- 지울 떄 필요함: ALTER TABLE DROP CONSTRAINT 제약명
	- 제약 추가: ALTER TABLE sample MODIFY .... (위에서 설명함)
#### 기본키
- 기본키로 지정할 열은 NOT NULL이 필수
- 중복이 있어서는 안됨
	- 다만, (이름, 주민등록번호) 이렇게 기본키를 두개 설정하면, 이름정도는 중복되도 상관없음
	- CONSTRAINT pkey PRIMARY KEY (name, citizen_no)

### 인덱스와 뷰
인덱스: 테이블에 붙여진 색인
- 검색속도의 향상
	- (SELECT WHERE을 이용한 검색을 목차,INDEX를 통해 빠르게 하게해줌)
- 테이블과 상관관계임: 내용없이 목차만 있는 책이 없듯이
- CREATE INDEX / DELETE INDEX로 작성/삭제 가능
- 실제로 검색에 쓰여서 속도를 향상시키는지는 EXPLAIN명령으로 확인 가능

뷰: 서브쿼리에 이름을 붙이고 데이터베이스 객체화 하여 쓰기 쉽게 한것
- CREATE VIEW 뷰 AS SELECT ~ / DROP VIEW 뷰 로 이용함
- SELECT명령은 객체가 아니고 VIEW는 객체임
- 간략하게 SELECT 서브쿼리를 표현가능
- 실제로 존재하지 않는 가상테이블이다.
	- materalized view를 이용해 실제 존재하는 테이블을 만들 수도 있고
		- view는 cpu를 이용(계산), materalized view는 데이터 용량을 이용
		- 자주 변경되지 않으면 이용할 만함, 대신 자주 변경된다면....?
	- 함수 테이블을 이용하여 상관 서브쿼리를 해결할 수 있음
	