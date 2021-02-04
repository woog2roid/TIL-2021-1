>REST(Representational State Transfer)는 HTTP/1.0과 1.1의 스펙 작성에 참여하였고 아파치 HTTP 서버 프로젝트의 공동설립자인 로이 필딩 (Roy Fielding)의 2000년 논문에서 처음 소개되었다. 발표 당시의 웹이 HTTP의 설계 상 우수성을 제대로 사용하지 못하고 있는 상황을 보고 웹의 장점을 최대한 활용할 수 있는 아키텍쳐로서 REST를 소개하였고 이는 HTTP 프로토콜을 의도에 맞게 디자인하도록 유도하고 있다. REST의 기본 원칙을 성실히 지킨 서비스 디자인을 “RESTful”이라고 표현한다.

## REST API
- URI는 자원을 표현하는 데에 집중하고,
- 행위에 대한 정의는 HTTP Method를 통해서

```
# bad
GET /getTodos/1

#good
GET /todos/1
```
- URI는 자원을 표현하며, 명사형을 이용한다.
- 자원에 대한 행위는 HTTP Method로 표현한다.

## HTTP Method
__5가지의 Method(GET, POST, PUT, PATCH, DELETE)를 이용하여 CRUD(create, replace, update, delete) 구성__

|Method|Action|역할|페이로드|
|:---:|:---:|:---:|:---:|
|GET|index/retrieve|모든/특정 리소스 조회| X
|POST|create|리소스 생성|O
|PUT|replace|리소스 전체를 교체|O
|PATCH|modify|리소스의 일부 수정|O
|DELETE|delete|모든/특정 리소스 삭제|O

## REST API 구성
__자원, 행위, 표현 (Resource, Verb, REpresentation)__  

|구성요소|내용|표현방법|
|:---:|:---:|:---:|
|Resource|자원|HTTP URI|
|Verb|자원에 대한 행위|HTTP Method|
|Representations|자원에 대한 행위의 내용|HTTP Message Pay Load|