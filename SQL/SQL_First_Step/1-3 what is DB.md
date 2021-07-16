SQL 첫걸음 책의 1강~3강을 정리한 내용.

### 1강
DB: 데이터베이스
DBMS: Database Manageent System
- DBMS를 통해 생산성 기능성 신뢰성을 얻는다.

SQL은 DBMS를 조작하는 언어, 정확히는 RDBMS 즉, 관계형 DB를 조작하는 언어이다.

SQL 명령에는 세 종류가 있다.
- DML: Data __MAnipulation__ Language (추가, 삭제, 갱신)
- DDL: Data __Definition__ Language (데이터를 정의하는 명령어)
- DCL: Data __Control__ Language (제어하는 명령어)

### 2강
DB의 종류
- 계층형 DB
- _관계형 DB_
- 객체지향 DB
- XML DB
- _키-값 DB (NoSQL이라고도 함)_

관계형 DB의 제품들에는  
_Oracle, DB2, SQL server, PostgreSQL, MySQL, SQLite_  
등이 있다.

SQL의 여러 제품군들이 생기며 SQL 제품군들만의 "고유 방언"이 생겨났다. 그 이후, 
표준화 작업이 진행되면서 표준화는 되었지만, 제품군들간 고유방언은 아직 있다.

### 3강
DB서버에 접근해서 SQL명령을 날리기전 사용자 인증이 필요하다.

웹앱 프로젝트를 할 때, CGI 프로그램이 DB서버의 클라이언트가 된다.

개인이 혼자 할 때는 루프백 접속을 통해 하기도 한다.