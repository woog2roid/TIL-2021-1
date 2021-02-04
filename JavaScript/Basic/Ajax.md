### Ajax (Asynchoronous JavaScript and XML)

- 서버는 request에 대한 reply로 요청받은 페이지(HTML)을 반환하는데 당연히, CSS나 JS파일들도 같이 반환된다.
  - 정적인 파일일 수도, 서버 사이드 프로그램이 만들어낸 파일이나 데이터를 반환할 수도 있다.
  - 클라이언트의 브라우저는 이를 렌더링하여 화면에 표현한다.

__Ajax는 자바스크립트를 이용해서 _비동기적_ 으로 서버와 브라우저가 데이터를 교환할 수 있는 통신방식을 의미한다.__

- 화면 전체가 아닌 페이지 일부만을 갱신하게 하도록 함
  - 빠른 퍼포먼스와 부드러운 화면 표시 효과

### JSON (JavaScript Object Notation)
__Ajax Request에 JSON을 reply로 보내주면, client는 DOM Manipulation을 한다.__

- 일반 텍스트 포맷보다 효과적인 데이터 구조화 가능
- XML 포맷보다 가볍고 사용하기 편리한 구조
- 가독성이 뛰어남 
- _순수한 텍스트로 구성된 규칙이 있는 데이터 구조_

```JSON
{
    "name": "Woo",
    "gender": "male"
}
```
과 같이 쓴다
- 키는 반드시 큰 따옴표로 둘러 싸야한다.

__JSON.stringify__  
__객체를 JSON 형식의 문자열로 반환한다.__  

```javascript
const o = {name: 'Woo', gender:'male'};

const strObject = JSON.stringify(o);
//strObject = {"name":"woo", "gender":"male"}
```

__JSON.parse__  
__JSON 데이터를 객체로 변환함(역직렬화)__  
- 서버에서 브라우저로 전송된 JSON 데이터는 문자열이므로, 이용하기 위해서는 객체화 하여야 하는데 이를 역직렬화(Deserializing)이라 한다.

```javascript
const todos = [
  { id: 1, content: 'HTML', completed: true },
  { id: 2, content: 'CSS', completed: true },
  { id: 3, content: 'JavaScript', completed: false }
];

// 배열 => JSON 형식의 문자열
const str = JSON.stringify(todos);
console.log(typeof str, str);
/*
string [{"id":1,"content":"HTML","completed":true},{"id":2,"content":"CSS","completed":true},{"id":3,"content":"JavaScript","completed":false}]
*/

// JSON 형식의 문자열 => 배열
const parsed = JSON.parse(str);
console.log(typeof parsed, parsed);
/*
object 
(3) [{…}, {…}, {…}]
0: {id: 1, content: "HTML", completed: true}
1: {id: 2, content: "CSS", completed: true}
2: {id: 3, content: "JavaScript", completed: false}
length: 3
*/
```

