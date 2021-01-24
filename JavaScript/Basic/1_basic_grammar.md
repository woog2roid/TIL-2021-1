## JavaScript의 특성
- 웹 브라우저에서 작동하는 유일한 프로그래밍 언어
- 멀티 패러다임 프로그래밍 언어
  - 명령형, 함수형, 프로토타입 기반 객체지향 프로그래밍 지원  
- ES6의 import/export가 지원이 안되어서 webpack과 같은 모듈 bundler가 필요
- 구형 브라우저를 위해 babel과 같은 트랜스파일러가 필요

## JavaScript의 기본 문법
### 변수
__JavaScript는 동적 타이핑을 지원한다.__
- 원시 자료형
  - number, string, boolean, null, undefined, symbol
- 객체 자료형
  - object

### 함수
```javascript
function hi(){
    alert("hi");
}
```
와 같이 간단히 function으로 만들면 된다.

### 객체
__프로퍼티(데이터)와 메소드(함수)로 구성된 집합__
```javascript
var person = {
  name: 'woo',
  gender: 'male',
  sayHello: function () {
    console.log('Hi! My name is ' + this.name);
  }
};
```
와 같이 선언할 수 있다. 굳이 다른 data type을 이용할 필요가 없다.

### 동등비교, 일치비교
|비교 연산자	|의미	|사례	|설명|
|:---:|:---:|:---:|:---:|
|==|	동등 비교|	x == y|	x와 y의 값이 같음|
|===|	일치 비교	|x === y|	x와 y의 값과 타입이 같음|
|!=|	부등 비교	|x != y|	x와 y의 값이 다름|
|!==	|불일치 비교|	x !== y|	x와 y의 값과 타입이 다름|

