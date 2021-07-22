SQL 첫걸음 책의 9강~11강을 정리한 내용.

### 9~10강
__"SELECT 열명 FROM 테이블명 WHERE 조건식 ORDER BY 열명 ASC/DESC"__

- ORDER BY 뒤에 열명을 적으면 그 열(column)을 기준으로 순서대로 정렬된다.
	- 원본 테이블에는 변화를 주지 않는다.
		- DB서버에서 클라이언트로 보내줄 때, 정렬해서 값을 보내주는 것임.
- ASC는 오름차순 DESC는 내림차순을 의미한다. 
	- 생략하면 ASC가 기본으로 적용된다.
	
__"SELECT * FROM sample1 WHERE ~~~ ORDER BY name ASC, birthday ASC"__

- 기준이 되는 열이 겹칠 때, 여러개의 열을 통해 정렬할 수 있다.
	- 위의 예제는 우선 이름으로 정렬을 하고, 이름이 같으면 생일이 빠른 순서대로 정렬한 것이다.

__"참고"__
- ASC, DESC는 표준이 정해져있지 않아서 프러덕트에 따라 차이가 있을 수 있다.
- NULL 값의 경우에도 표준이 정해져있지 않아서 제품에 따라 차이가 있을 수 있다.
	- MySQL의 경우에는 NULL을 가장 작은 값으로 취급하긴 한다.
	
### 11강
__"SELECT * FROM sample1 ORDER BY bitrthday LIMIT 5 OFFSET 0"__
- 0번부터 시작해서 5개까지를 생일 별로 정리해서 sampel1에서 뽑아봐라

- OFFSET은 처음 시작하는 범위: 배열처럼 0에서부터 시작함
- LIMIT은 최대갯수를 의미함
	- LIMIT은 표준 SQL 문법이 아님, MySQL과 PostgreSQL에서만 동작