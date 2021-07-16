SQL 첫걸음 책의 4강~8강을 정리한 내용.

### 4강 (SELECT * FROM sample1;)
SELECT * FROM sample1;
- * 은 모든 열을 의미한다.
- FROM 뒤에는 테이블명이 나온다.

SQL은 대소문자를 구별하지 않으나 예약어는 대문자로,
나머지는 소문자로 써주는 것이 보기에 편하기 때문에 보통 위와 같이 작성한다.

SQL명령은 예약어(키워드)를 중심으로 '구'라는 단위로 나눌 수 있다.
- 위의 명령은 SELECT구와 FROM구로 나눌 수 있다.

테이블은 행/열로 구성된 표 형식의 data이다.
- 행: 레코드, ㅡ
- 열: 필드, ㅣ
- 셀: 한 칸(정확히는 행과 열이 만나는 곳)

### 5강 (DESC sample1;)
DESC samle1;
- sample1의 모든 열을 보여준다.
- 밑에는 공간의 여유가 없어서 세로로 적었는데, 원래 실행하면 보기좋게 테이블이 구성된다...
```
FIELD	
no		
name	
birthday
address	

Type		
int(11)		
varchar(20)	
date		
varchar(40)	

NULL
YES

Key

Default
NULL

Extra
```
과 같이 나온다고 하면,
- FIELD: 열의 이름들을 나열함
- Type: 열의 자료형들을 나열함
- NULL: YES면 해당열에 NULL값이 들어가도 됨을 의미함
- Key: 행을 대표하는 열인지 (Sequelize쓰면서 봤던 그것!)
- Default: 기본 값, 즉 생략했을 때 자동으로 들어가는 값

자료형
- INTEGER: 정수형
- CHAR: 고정길이, (10)에 woo를 넣으면 나머지는 알아서 공백으로 채워짐
- VARCHAR: 가변길이, (10)에 woo를 넣으면 알아서 크기가 줄어듬
- DATE: 날짜
- TIME: 시간

### 6-7강 (SELECT name, birthday FROM sample1 WHERE no > 3)
SELECT name, birthday FROM sample1 WHERE no > 3
- name과 birthday열만 본다.
- sample1이라는 테이블의,
- no가 3보다 큰 것들 중에서

문법: 구의 순서는 정해져있다 / 생략이 가능한 구도 있다.
- SELECT FROM WHERE의 순서는 정해져있어서, WHERE을 FROM 앞에 놓으면 안된다.
- WHERE구는 생략이 가능하다.

조건식 쓰는 법 (연산자)
- =, <, >, <=, >= 는 모두 같은데 '다르다'연산자가 !=이 아니고 <> 이 된다.
- NULL은 'IS NULL'과 'IS NOT NULL'을 이용할 수 있다.

조건식 쓰는 법 (자료형)  
WHERE name = 'woog2roid'  
WHERE time = 10:35:43  
WHERE date = 2021-07-16  
- 문자열 자료형은 '(single quote)로 둘러싸야 한다.
- 날짜시간형은 연월일을 -(하이픈)으로, 시각은 시분초를 :(콜론)으로 구분해야 한다.

AND, OR, NOT으로 조건문을 중첩시킬 수 있다.
- AND가 OR보다 먼저 계산된다. 생각치못한 오류를 피하려면 괄호를 치자

### 8강 (패턴매칭 SELECT * FROM sample WHERE text LIKE '%SQL%')

열명 LIKE '패턴'
- LIKE는 수치형 상수는 지정할 수 없으며 보통 문자열을 패턴매칭 시킴
- %는 임의의 문자열, _ 는 임의의 문자 하나

SELECT * FROM sample WHERE text LIKE '%SQL%'
- sample에서 text열에 SQL이 포함되어 있는 레코드들의 모든 열을 내보내라
- SQL%, %SQL이었으면 SQL로 시작하거나 끝나는 걸 의미함


escape 문자 (\)
- '%' 는 '\%'를 통해 검색
- _ 는 \ _ 를 통해 검색
- '가 문자열 상수에 포함되면 ''처럼 두번 붙이면 escape된다.