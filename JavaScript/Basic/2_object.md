## 객체
__property(key + value)들의 집합__
- property key: 빈 문자열을 포함하는 모든 문자열 또는 symbol 값
- property value: 모든 값
- 함수 프로퍼티는 method라고 부름

> ES6 에 들어서면서 javascript에도 class가 생겼다. 자바와 같은 클래스 기반 언어에 익숙하던 개발자들에게 장벽이 하나 줄어 든 셈이다.

## 객체 생성 방식
__객체 리터럴__
``` javascript
var person = {
  name: 'Woo',
  gender: 'male',
  sayHello: function () {
    console.log('Hi! My name is ' + this.name);
  }
};
```
와 같이 편하게 생성할 수 있다. 자동으로 작성된 property를 가지는 객체를 생성한다. 아무것도 없이 비어있다면 빈 객체를 생성한다.

__Object 생성자 함수__
```javascript
// 빈 객체의 생성
var person = new Object();
// 프로퍼티 추가
person.name = 'Woo';
person.gender = 'male';
person.sayHello = function () {
  console.log('Hi! My name is ' + this.name);
};
```
와 같이 작성하는데,  
 _사실상 거의 이용하지 않는다. 객체 리터럴로 생성하면 내부적으로 동일한 동작을 하기 떄문_

 __생성자 함수__
 ```javascript
 var person1 = new Person('Lee', 'male');
 ```
 와 같이 작성한다.  
 java에서보던 class 문법과 동일하다.

 ## 객체 프로퍼티 접근
 __프로퍼티 키__  
 ```javascript
 var person = {
  'last-name': 'Woo',
  gender: 'male',
  1: 10,
  function: 1 // OK. 하지만 예약어는 사용하지 말아야 한다.
};
 ```
 \' \'을 이용해서 표현하는 경우는 last-name과 같이 javascirpt에서 허용이 가능하지 않은 이름인 경우이다. (물론 허용되는 경우에 써도 문제가 되진 않는다.) 허용이 불가능한 이유는 -연산자가 들어가기 때문...

 ```javascript
 [first-name]:'Woo'
 ```
 와 같이 대괄호를 이용하여 작성하면 표현식이 된다. 물론 
 'first'변수와 'name'변수가 없어서 오류가 뜰 것이다.

 __프로퍼티 값 읽기__
 ```javascript
console.log(person.last-name);    // NaN: undefined-undefined
console.log(person[last-name]);   // ReferenceError: first is not defined
console.log(person['last-name']); // 'Woo'
 ```
- 객체에 존재하지 않는 프로퍼티의 경우에는 undefined를 반환한다.
- 대괄호 표기와 .을 이용한 표기가 있다.
  -  유효하지 않은 javascript 이름이거나 예약어와 동일한 경우에는 대괄호 표기법을 이용하여서 읽어야한다.
  - 대괄호 내에 들어가는 프로퍼티 이름은 반드시 문자열이다.

__프로퍼티 동적 생성 / 추가__
```javascript
person.age = 20;
```
존재하지 않는 프로퍼티 키를 할당하면 저절로 추가된다.

```javascript
delete person.age;
```
delete를 이용해서 삭제할 수 있다.

__for~in문__
```javascript
for (var prop in person) {
  console.log(prop + ': ' + person[prop]);
}
/*
last-name: Woo
gender: male
*/
```
와 같이 사용하면, "prop"에 person의 property가 들어가게 된다.

하지만 객체의 프로퍼티에는 사용이 가능하지만 배열의 경우에는,
- 순서가 보장이 되지 않을 뿐 아니라
- 배열의 요소만 순회하지 않기 떄문에

사용이 불가능하다.

```javascript
// 배열 요소들만을 순회하지 않는다.
var array = ['one', 'two'];
array.name = 'my array';

for (var index in array) {
  console.log(index + ': ' + array[index]);
}

/*
0: one
1: two
name: my array
*/
```
그렇기 때문에 ES6에서는 for~of문이 추가되어서 배열에서도 사용이 가능하게 되었다.
```javascript
for (const value of array) {
  console.log(value);
}
```

## pass by reference/value
object type의 경우 변수는 C에서의 포인터와 같이 해당 객체의 주소값을 가지기 떄문에,
```javascript
var foo = { val: 10 };
var bar = { val: 10 };

console.log(foo.val, bar.val); // 10 10
console.log(foo === bar);      // false

var baz = bar;

console.log(baz.val, bar.val); // 10 10
console.log(baz === bar);      // true
```
이러한 결과가 나온다.  
즉, object는 pass-by-reference 방식을 이용한다.

## 객체의 분류
- Object
  - Host Object(사용자 정의 객체)
  - Built-in Object(내장 객체)
    - Standard Built-in Object(표준 내장 객체)
    - Native Object
      - DOM
      - BOM