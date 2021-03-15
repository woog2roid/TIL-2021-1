## 서버 기본
> localhost와 port란?  
> - localhost: 현재 컴퓨터의 내부 주소.
>   - 외부에서는 접근할 수 없고 자신의 컴퓨터에서만 접근할 수 있으므로, 서버 개발 시 테스트용으로 많이 사용됨.
>   - 127.0.0.1로 해도 동일
> - port: 서버 내에서 프로세스를 구분하는 번호
>   - 21(FTP), 80(HTTP), 443(HTTPS), 3306(MYSQL)등이 있음
>   - 보통 포트 하나에 서비스를 하나만 사용할 수 있음

```javascript
const http  = require('http');
const fs = require('fs').promises;

http.createServer(async (req, res) => {
    try {
        const data = await.fs.readFile('./server.html');
        res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'});
        res.end(data);
    } catch (err) {
        console.error(err);
        res.writeHead(500, {'Content-Type': 'text/html; charset=utf-8'});
        res.end(err.message);
    }
})

    .listen(8080, () => {
        console.log('8080번 포트에서 대기 중');
    })

```
- fs 모듈로 HTML 파일을 보내주는 형식
  - 이게 아니면, 직접 res.write res.end에 HTML을 써야함...
- writeHead에는 헤더를 적어주기
  - 첫 번째 인수에는 status code를 적어주게 되어있다.
  - 두 번쨰 인수에는 응답에 대한 정보의 콘텐츠의 형식이 HTML임을 알리고 있음
- createServer 메서드 뒤에 listen을 붙이고 클라이언트에 공개할 포트 번호와 콜백함수를 적음

```javascript
const server = http.createServer((req, res) => {
// 생략
});
server.listen(8080);

server.on('listening', () => {
    console.log('8080번 포트에서 서버 대기중입니다.');
});
sever.on('error', (error) => {
    console.error(error);
})
```
- 이와 같이 적을 수도 있음
- 위와 동일하게 작동하긴 하는데 server라는 변수를 만들어주어서 listen과 error를 처리함

## REST(Representational State Transfer)
__서버의 자원을 정의하고 자원에 대한 주소를 지정하는 방법__
- GET: 서버에서 자원을 가져옴
- POST: 서버에 자원을 새로 등록함
- PUT: 서버의 자원을 치환할 때
- PATCH: 서버 자원의 일부만 수정할 때
- DELETE: 서버의 자원을 삭제할 때
- OPTIONS: 요청을 하기 전에 옵션을 설명

POST, PUT, PATCH는 데이터를 함께 서버에 보내게 된다.

추가적으로 주소의 명명법등은 [여기](https://gmlwjd9405.github.io/2018/09/21/rest-and-restful.html)를 보면 도움이 될듯...

## 라우팅
```javascript
// 소스코드가 긴 관계로... 
// https://github.com/ZeroCho/nodejs-book/blob/master/ch4/4.2/restServer.js
```
소스코드를 살펴보면
- GET인 경우에 /, /about, /users를 if문으로 나눠서 어떤거를 줄지 정함
- POST인 경우에도 동일하게 나눠서 등록함
- ...이하 동일
- req, res도 stream으로 구성되어 있으므로, req.on('data')와 같은 것들이 가능해짐
 
__문제점들__
1. 코드가 너무 길고 더러워짐 --> express같은 프레임워크의 등장
2. 데이터가 서버 메모리에 변수 형태로 저장되므로 서버를 종료하면 데이터가 소실 --> DB의 필요성