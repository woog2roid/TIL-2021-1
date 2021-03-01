## 불변성
- 리액트에서는 불변성이 지켜지지 않으면, 내부의 값이 새로워져도 인식하지 못함
  - React.memo에서 비교가 불가능
- 전개연산자로는 구조가 복잡한 객체를 불변성을 유지하면서 고치기가 힘듬

## immer(상태, 함수)
- immer는 불변성을 유지할 수 있도록 도와주는 라이브러리임
  - yarn add immer로 추가해서 사용가능
  
```javascript
import produce from 'immer'
const nextState = produce(originalState, draft => {
    draft.somewhere.deep.inside = 5;
});
```
와 같이
- 첫 번째 파라미터에는 수정하고 싶은 state를
- 두 번째 파라미터에는 함수를(이 함수 안에서 state를 수정하면 된다.)

넣어서 써주면 된다.
- oneRemove의 경우에는 filter를 사용하는 것이 더 편리할 수도 있음

## immer(함수)
- 첫 번째 파라미터로 함수가 들어오면 업데이트 함수를 반환한다.
```javascript
const update = produce(draft => {
    draft.value = 2;
});

const originalState = {
    value: 1,
    foo: 'bar'
};

const nextState = update(originalState);
console.log(nextState); // {value: 2, foo: 'bar'}
```
