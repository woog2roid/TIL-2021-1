## useState
함수형 컴포넌트에서도 가변적인 상태를 지닐 수 있게 해줌

```javascript
import React, { useState } from 'react'
const [value, setValue] = useState(0);
```
- useState는 import를 통해 불러오고, useState 함수의 파라미터에는 상태의 기본값을 넣어준다.
- 함수는 호출되면 배열을 반환한다. 
  - __배열의 첫 번째 원소는 상태값, 두 번째 원소는 상태를 설정하는 함수.__
```javascript
    return (
        ...
        <button onClick = {() => setValue(value + 1)}> +1 </button>
        <button onClick = {() => setValue(value - 1)}> -1 </button>
        ...
    )
```
- 바로 setValue 함수 이용가능
- useState로 여러개의 state도 당연히 관리 가능 
## useEffect
리액트 컴포넌트가 렌더링될 때마다 특정 작업을 수행하도록 설정할 수 있는 Hook
```javascript
useEffect(() => {
    console.log('렌더링이 완료되었습니다.!');
});

useEffect(() => {
    console.log('렌더링이 완료되었습니다.!');
}, []);

useEffect(() => {
    console.log('렌더링이 완료되었습니다.!');
}, [name]);
```
- 업데이트(리렌더링) 될 때는 사용하고 싶지 않으면, 뒤에 배열을 붙여서 이용가능
- 배열안에 검사하고 싶은 값을 넣어주면 특정 값이 업데이트 될 떄만 사용 가능
## useReducer
useState보다 더 다양한 컴포넌트 상황에 따라 다양한 상태를 업데이트할 때 사용하는 Hook
- 리듀서: 현재 상태, 업데이트를 위해 필요한 정보를 담은 액션 값을 전달받아 새로운 상태 반환
- 항상 불변성을 유지시켜주어야 함
- useReduce를 이용하면 컴포넌트 업데이트 로직을 컴포넌트 바깥으로 빼낼 수 있음
```javascript
import React, { useREducer } from 'react';

function reducer(state, action) {
    switch (action.type) {
        case 'INCREMENT' :
            return {value: state.value + 1};
        case 'DECREMENT' : 
            return {value: state.value - 1};
        default :
            return state;
    }
}

const [state, dispatch] = useReducer(reducer, {value : 0});

return (
    ...
    <button onClick = {() => dispatch({type: 'INCREMENT'})}>+1</button>
    <button onClick = {() => dispatch({type: 'DECREMENT'})}>-1</button>
    ...
);
```
- useState와 마찬가지로 state와 dispatch(setState)를 반환한다.
  - dispatch는 액션을 발생시키는 함수이다.
- useReducer의 파라미터로 reducer 함수와 기본값을 넣는다.
## useMemo
컴포넌트 내부에서 발생하는 연산을 최적화할 수 있다.
```javascript
const avg = useMemo(() => getAverage(list), [list]);
```
와 같이 이용하면 list 배열의 내용이 바뀔 떄만 getAverage함수가 호출된다. (평균구하기 예제)
## useCallback
주로 렌더링 성능을 최적화해야 하는 상황에서 이용
- 물론 얘도 똑같이, 첫번째 parameter에는 콜백함수를, 두번째에는 변화하는 배열을 넣는다
```javascript
const onInesert = useCallback (() => {
    ...
}, [number, list]);
```
- number혹은 list가 바뀌었을 때만 함수를 생성한다는 뜻...
- 이렇게 선언하면 컴포넌트가 리렌더링될 때마다 새로 만들어진 함수를 사용하지 않게 됨
## useRef
- 함수형 컴포넌트에서 ref를 쉽게 사용할 수 있도록 해줌
- useRef를 사용하여 ref를 설정하면 useRef를 통해 만든 객체 안의 current 값이 실제 엘리멘트를 가리킴
  - const inputEl = useRef(null); -> inputEl.current.focus();