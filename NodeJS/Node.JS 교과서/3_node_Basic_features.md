## REPL?
REPL(Read Eval Print Loop)
- 노드의 콘솔을 부르는 것. 읽고 해석하고 반환하고 종료할 때까지 반복한다고 하여서 붙인 이름.
- 터미널에서 node를 입력해서 이용할 수 있음
- js 파일은 터미널에서 "node <파일명>"을 쳐서 이용할 수 있음

## Module
- 크롬 60부터 브라우저에서도 모듈을 사용할 수 있음
  - 원래는 브라우저에서는 모듈이 지원이 안되었었음
- ES2015부터 JS에도 자체적으로 모듈 시스템 문법이 생겼는데 이는 노드의 기존 모듈 문법과 다름
  - package.json에 type:"module"을 넣어야 js확장자에 ES2015문법을 이용가능
```javascript
//node style
const {odd, even} = require('./var');
//ES2015
import {odd, even} from './var';
```
## 내장객체-global
- 브라우저의 window 객체와 같은 전역 객체
  - 모든 파일에서 접근 가능
  - global은 생략가능 (window.open --> open / global.require --> require)
  - 파일 간에 간단한 데이터를 공유할 때 이용되기도 함 (권장되지는 않음)
## 내장객체-console
- 보통 디버깅을 위해 사용되는 객체
  - console.log()가 대표적임
  - console.error(): 에러 메세지는 console.error로 처리
  - console.table(): 배열의 요소를 넣으면 속성들이 테이블 형식으로 표현됨 
## 내장객체-global.타이머
setTimeout과 같은 객체들이 global에 들어있음
- setTimeout(콜백, 밀리초): 밀리초(1/1000 초) 이후에 콜백함수 실행
- setInterval(콜백, 밀리초): 밀리초마다 콜백함수 실행
- setImmediate(콜백): 콜백함수를 즉시 실행

이러한 타이머 함수들은 모두 고유한 아이디를 반환하는데 이러한 아이디를 이용하여 타이머를 취소할 수 있다.
- clearTimeout(아이디): setTImeout을 취소
- clearInterval(아이디): setInterval을 취소
- clearImmediate(아이디): setImmediate을 취소
## 내장객체-__filename, __dirname
현재 파일의 경로나 파일명을 알게 해줌
- __filename: C:\Users\example\filename.js
- __dirname: C:\Users\example
## 내장객체-process
현재 실행되고 있는 노드 프로세스에 대한 정보를 담는다
- process.env: 시스템의 환경 변수
  - 서비스의 중요한 키를 저장하는 공간이므로 중요한 속성은
    ```javascript
    cosntId = process.env.SECRET_ID; constCode = process.env.SECRET_CODE;
    ```
    와 같이 입력하여야함
- process.nextTick(콜백): 이벤트 루프가 다른 콜백 함수들보다 nextTick의 콜백함수를 우선적으로 처리하도록 함

