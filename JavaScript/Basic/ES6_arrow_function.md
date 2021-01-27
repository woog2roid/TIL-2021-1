## arrow function
__ES6부터는 fucntion 키워드 대신 =>를 이용해서 간단하게 함수를 선언할 수 있지만, 모든 경우 화살표 함수를 사용가능한 것은 아니다__

```javascript
//기본적인 문법
(x, y) => { 
    return x * y;
}

//매개변수가 하나이면 ()을 생략가능하다
x => {return x*x;}

//또한 함수 몸체가 한 줄이라면 {}을 생략가능하며, return도 암묵적으로 생략가능하다.
x => x*X

// 화살표 함수는 익명함수로만 사용 가능, 따라서 호출하기 위해서는 함수표현식 이용
const pow = x => x * x;
const pow = (x) => {return (x * x);}

// 또는 콜백함수로 이용하면 상당히 깔끔하다
const pow = arr.map(x => x * x);
```

- this 키워드는 언제나 상위스코프를 가리킨다
  - 그렇기 때문에, 함수 선언과 prototype에서는 이용하면 안된다.
  - 화살표함수는 prototype 프로퍼티가 없어서, 생성자함수로 이용하면 안된다.
  - addEventListner의 콜백함수롱 이용하면 안된다.