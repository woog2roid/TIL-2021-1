## 함수 정의하기
__함수 선언문, 함수 표현식의 방법이 있으며,__  
Function 생성자 함수 ("new funciton()")를 이용하는 방법도 있지만 사용하지 않는다.

__함수 선언문__
```javascript
var square = function square(number) {
  return number * number;
};
```
__함수 표현식__
```javascript
// 기명 함수 표현식
//multiply가 아닌 square로 호출해야함
var square = function multiply(number) {
    return number * number
}

// 익명 함수 표현식
var square = function(number) {
  return number * number;
};
```
_함수 표현식 방법을 주로 이용한다._


## 일급객체
__자바스크립트의 함수는 일급객체이다.__
> 일급객체: 생성, 대입, 연산, 인자 또는 반환값으로서의 전달 등 프로그래밍 언어의 기본적 조작을 제한없이 사용할 수 있는 대상을 의미한다.
1. 무명의 리터럴로 표현이 가능하다.
2. 변수나 자료구조에 저장할 수 있다.
   - 변수에 함수를 할당하면, 변수에는 함수의 주소값이 저장됨
3. 함수의 파라미터로 전달할 수 있다.
4. 변환값으로 사용할 수 있다.

JavaScript의 함수는 일급객체이므로 흡사 변수와 같이 사용할 수 있으며 코드의 어디에서든지 정의할 수 있다.
- 함수와 다른 객체를 구분짓는 특징은 호출할 수 있다는 것이다.

## 호이스팅(Hoisting)
__var 선언문이나 function 선언문 등 모든 선언문이 해당 scope의 선두로 옮겨진 것처럼 동작하는 특성__

함수 선언문으로 정의된 함수는 자바스크립트 엔진이 로딩되는 시점에 초기화된다. 즉, 함수선언, 초기화 할당이 한번에 이루어진다. 소스의 위치와 상관이 없게 말이다.

함수 표현식으로 정의하게 되면, 변수 호이스팅이 발생하게 된다. 함수 호이스팅과는 달라서, 초기화가 undefined로 되게 된다.

- __함수 호이스팅이 호출전 반드시 함수를 선언하여야 한다는 규칙을 무시하므로 코드의 구조를 엉성하게 할 수 있다.__
- __함수 선언문은 정의에 편리하긴 하지만, 인터프리터가 너무 많은 코드를 분석해서 변수 객체(variable object)에 저장하므로 속도가 느릴 수 있다.__

## 프로퍼티
__함수는 객체이기 때문에 프로퍼티를 갖는다.__
- 하지만 함수는 일반 객체와는 다른 함수만의 프로퍼티를 갖는다.

|프로퍼티 이름|의미|
|:---:|:---:|
|arguments|함수 호출 시 전달된 인수들의 정보를 담고있는 iterable 객체|
|caller|자신을 호출한 함수|
|length|함수 정의 시 작성된 parameter의 갯수|
|name|함수 명, 익명함수의 경우 빈 문자열|
|\_\_proto\_\_|프로토타입 객체 접근|
|prototype|함수가 객체를 생성하는 생성자 함수일 때, 생성한 인스턴스의 프로토타입 객체|

## 함수 종류
__즉시 실행 함수__ _함수의 정의와 동시에 실행되는 함수_
```javascript
// 기명 즉시 실행 함수(named immediately-invoked function expression)
(function myFunction() {
  var a = 3;
  var b = 5;
  return a * b;
}());

// 익명 즉시 실행 함수(immediately-invoked function expression)
(function () {
  var a = 3;
  var b = 5;
  return a * b;
}());
```
함수를 통째로 묶어야 한다.

즉시 실행 함수에 처리 로직을 모아두면 변수명이나 함수명의 충돌을 방지할 수 있다.
_자바스크립트에서는 파일이 분리되어있어도 글로벌 스코프가 하나이기 때문에 예기치 못한 충돌이 있을 수 있다._

__내부 함수__
_함수 내부에 정의된 함수_
```javascript
function parent(param) {
  var parentVar = param;
  function child() {
    var childVar = 'lee';
    console.log(parentVar + ' ' + childVar); // Hello lee
  }
  child();
  console.log(parentVar + ' ' + childVar);
  // Uncaught ReferenceError: childVar is not defined
}
parent('Hello');
```
- C언어 scope 문법과 동일하게, 부모는 자식의 변수에 접근이 불가능 하지만 역은 가능하다.
- 내부 함수는 부모 함수 외부에서는 접근이 불가능하다.

__콜백 함수__
_명시적으로 호출하는 것이 아니라 특정 이벤트가 발생하면 시스템에 의해 호출되는 함수이다._
```html
 <script>
    var button = document.getElementById('myButton');
    button.addEventListener('click', function() {
      console.log('button clicked!');
    });
  </script>
```
이벤트 핸들러 처리에서 자주 이용된다.
- 주로 비동기식 처리 모델(Asynchronous processing model)에서 이용된다.
