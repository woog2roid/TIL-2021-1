SQL 첫걸음 책의 22강을 정리한 내용.

### 그룹화
GROUP BY를 이용해 집계함수로 넘겨줄 집합을 "그룹" 단위로 나눌 수 있다.

__SELECT name FROM sample GROUP BY name;__
- sample 테이블을 name을 기준으로 GROUP화 한다.
- __GROUP BY를 쓰면, SELECT에 그룹화 되지 않은 열을 그대로 넣을 수 없다. 집계함수를 이용하지 않으면,__
	- 왜냐면, GROUP을 기준으로 행이 만들어지는데, 그룹화 되지 않은 열들은 어떤 값이 나와야하는지 모르니까...
		- 고등학교 전교생을 학년별로 그룹화하고, SELECT에 grade와 height를 넣었다. grade는 세개 나오는데 height는 1500개 나온다. AVG를 쓰는게 맞지 않을까?

그룹화를 쓰는 이유?  
```
ㅇㅇ고등학교의 전교생을 학년별로 묶어서 SELECT한다.
--> GROUP BY grade;

ㅇㅇ 고등학교의 전교생을 학년별, 성별로 묶어서 SELECT한다.
--> GROUP BY grade, gender;
(그룹이 여러개면 그만큼 집합, 다른 말로는 행이 많이 생긴다.)
```

#### HAVING 구
- 조건을 지정할 때 사용한다.
	- SELECT name, COUNT(name) FROM sample
	WHERE COUNT(name) = 1 GROUP BY NAME=1; _"오류"_
	- SELECT name, COUNT(name) FROM sample
	GROUP BY name HAVING COUNT(name)=1 _"작동"_

```
WHERE -> GROUP BY -> SELECT -> ORDER 순으로 처리하므로
GROUP BY에서 나온거를 WHERE에 넣을 수 없다.
```

#### ORDER BY
ORDER BY문을 통해 정렬할 수 있다.