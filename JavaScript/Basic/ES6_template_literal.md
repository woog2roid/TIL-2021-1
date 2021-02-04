## template literal
__ES6에서 새로 도입된 새로운 문자열 표기법/ \' \" 대신 \`을 이용한다.__

템플릿 리터럴만의 특징
- 몇 줄에 걸쳐 문자열 작성 가능
- white-space는 있는 그대로 적용됨
- 문자열 인터폴레이션으로 새로운 문자열 삽입 가능

```javascript
const first = 'XX';
const last = 'Woo';

// ES6: String Interpolation
console.log(`My name is ${first} ${last}.`);
// "My name is Woo XX."
console.log(`1 + 1 = ${1 + 1}`);
// "1 + 1 = 2"
```