## DB 생성하기
> mysql -h localhost -u root -p  
> exit

- -h뒤에는 접속할 수로를, -u뒤에는 사용자명을 입력함 -p는 비밀번호 사용 여부

> CREATE SCHEMA \`nodejs\` DEFAULT CHARACTER SET utf8;  
> use nodejs;

- nodejs라는 데이터베이스를 만들고, 사용하겠다는 뜻
- DEFAULT CHARACTER SET utf8은 한글을 입력할 수 있게 붙인 것
- 문법
  - 보통 예약어는 대문자로 사용하고, 예약어가 아닌 경우에 소문자로 씀
  - 세미콜론을 붙이지 않으면 프롬프트에서 다음줄로 넘어가서 계속 입력을 기다림

## 테이블 생성하기
> CREATE TABLE nodejs.users (  
> id INT NOT NULL AUTO_INCREMENT,  
> name VARCHAR(20) NOT NULL,  
> age INT UNSIGNED NOT NULL,  
> comment TEXT NULL,
> created_at DATETIME NOT NULL DEFAULT now(),  
> PRIMARY KEY(id),  
> UNIQUE INDEX name_UNIQUE (name ASC))  
> COMMENT = '사용자 정보'  
> DEFAULT CHARACTER SET = utf8  
> ENGINE = InnoDB;

- 커뮤니티의 유저를 저장하는 테이블을 만들기
- nodejs DB에 users라는 테이블을 만들어라 라는 뜻
- column들은 id, name, age, married, comment, created_at을 만들었음

옵션 설명
- __INT:__ 정수를 의미함 (소수의 경우에는 FLOAT이나 DOUBLE 이용 가능)
  - __UNSIGNED:__ 음수 적용 X
- __NULL/NOT NULL:__ 비어있어도 되는지 안되는 지를 의미함
- __VARCHAR(자릿수)/ CHAR(자릿수)__: VARCHAR(20)은 0~20까지 넣을 수 있다는 걸 의미하고, CHAR(20)은 무조건 20으로 맞추겠다는 뜻(부족한 자릿수는 스페이스로 맞춰줌) 
- __TEXT:__ 긴 글을 저장
- __DATETIME:__ 시간에 대한 정보를 담음. 날짜만 쓰는 DATE와 시간만 쓰는 TIME도 따로 있음
- __AUTO_INCREMENT:__ 자동으로 올리겠다는 뜻 1,2,3,4... ID에 사용했음
- __ZEROFILL:__ 숫자의 자릿수가 고장되어있으면 나머지 자리에 모두 0을 넣음 (가끔 INT(4) 처럼 써서 4자리수를 받을 때가 있음)
- __DEFAULT:__ 기본값 설정, 따로 들어오지 않으면 설정된 기본값으로 넣음
- __PRIMARY KEY:__ "기본 키(로우를 대표하는 고유한 값, 보통 ID)"임을 알려줌
- __UNIQUE INDEX:__ 해당 값이 고유해야 하는지에 대한 옵션, ID도 물론 고유해야 하지만 PRIMARY KEY가 붙어있을 경우에 안 붙여도 됨
- __COMMENT:__ 테이블에 대한 보충 설명을 의미함
- __DEFAULT CHARACTER SET:__ 캐릭터 셋 설정
- __ENGINE:__ 보통 여러가지가 있지만 MyISAM과 InnoDB가 많이 사용됨

> DESC users;

를 통해 테이블을 확인 가능

> SHOW TABLES;

를 통해 만든 테이블 모두를 확인 가능

> DROP TABLE users;

를 통해 테이블을 제거 가능

> commenter INT NOT NULL,  
> CONSTRAINT commenter FOREIGN KEY (commenter) REFFERENCES nodejs.users (id)

와 같이 작성하면 _외래키_ 라는 개념을 이용가능한데,  
다른 테이블의 기본키를 저장하는 컬럼임

"CONSTRAINT \[제약조건명\] FOREIGN KEY \[컬럼명\] REFERENCES \[참고하는 컬럼명\] "으로 이용가능

## MySQL CREATE (CRUD)
> INSERT INTO nodejs.users (name, age married, comment) VALUES ('zero', 24, 0, '저는 ~~ 입니다');

"INSERT INTO \[테이블명\] (\[컬럼1\]....) VALUES (\[값1\]...)"로 테이블에 삽입가능

## MySQL READ (CRUD)
> SELECT * FROM nodejs.users;

*를 통해 해당 테이블의 모든 데이터를 조회가능

__원하는 컬럼만 조회하기__  
SELECT ~ FROM ~ ;
> SELECT name, married FROM nodejs.users;  

_name과 married만 nodejs.users에서 조회함_

__특정 조건을 가진 데이터만 조회하기__
SELECT ~ WHERE ~;
> SELECT name, married FROM nodejs.users WHERE married = 1 AND age > 30;

name과 married만 nodejs.users에서 조회함  
_+ 나이가 30살 보다 많고 결혼을 한 사람중에_  
(OR 과 AND를 이용가능함)

__데이터 정렬하기__
SELECT ~ ORDER BY ~;
> SELECT name, married FROM nodejs.users ORDER BY age DESC;

name과 married만 nodejs.users에서 조회함  
_+ 나이가 많은 순서대로_  
(DESC는 내림차순 ASC는 오름차순)

__조회할 로우의 갯수를 설정하기__
SELECT ~ LIMIT ~;
>SELECT id, name FROM nodejs,users ORDER BY age DESC LIMIT 1;

id와 name만 nodejs.users에서 조회함  
나이가 많은 순서대로  
_+ LIMIT 1, 즉 한 개만_ 
`
__건너뛸 (OFFSET) 갯수 설정하기__
SELECT ~ OFFSET ~;
> SELECT id, name FROM nodejs.users ORDER BY age DESC LIMIT 1 OFFSET 1;

id와 name만 nodejs.users에서 조회함  
나이가 많은 순서대로  
LIMIT 1, 즉 한 개만  
_+ 1번은 건너뛰고 2번부터, 즉 2등만 올려라_

## MySQL UPDATE (CRUD)
> UPDATE nodejs.users SET comment = '바꿀 내용' WHERE id = 2;

UPDATE \[테이블명\] SET \[컬럼명 = '바꿀값'\] WHERE \[조건\];

## MySQL DELETE (CRUD)
> DELETE FROM nodejs.users WHERE id = 2;
