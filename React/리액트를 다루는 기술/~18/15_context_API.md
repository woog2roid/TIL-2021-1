## context API
context API: 전역상태 관리를 위함
- 리액트 애플리케이션은 컴포넌트 간에 데이터를 props로 전달하기 때문에 컴포넌트 여기저기서 필요한 데이터가 있을 때는 주로 최상위 컴포넌트인 App의 state로 넣어서 관리함
- __Context API를 이용하면 Context를 만들어서 단 한번에 원하는 값을 받아올 수 있음__

### 새 context 만들기
```javascript
import { createContext } from 'react';
const ColorContext = createContext({color: 'black'});
```
- createContext를 이용함
- parameter에는 Context의 기본 상태를 지정함

### Consumer 사용하기
- Consumer 사이에 중괄호를 열어서 함수를 넣어줌
  - function as a child, render props
- context의 consumer를 이용해서 context의 value 사용
```javascript
import ColorContext from '../context/color';

const ColorBox = () => {
    <ColorContext.Consumer>
        { value => (
                <div
                    style={{
                        width: '64px',
                        height: '64px',
                        background: value.color
                    }}
                />
            )}
    </ColorContext.Consumer>
};
```

### Provider 사용하기
- Context의 value를 변경 가능
- provider를 사용할 때는 항상 안에 value를 넣어야 오류가 발생하지 않음
```javascript
import ColorContext from './context/color';

const App = () => {
    return (
        <ColorContext.Provider value={{ color = 'red' }}>
            <div>
                <ColorBox />
            </div>
        </ColorContext.Provider>
    );
};
```

### 동적 context
- Context에는 함수를 넣어서 전달해 줄 수 있음

## Consumer 대신 Hook 또는 static contextType 이용하기
### useContext Hook 이용
```javascript
const ColorBox = () => {
    const { state } = useContext(ColorContext);
    
    return (
      <div
        style = {{
            width: '64px',
            height: '64px',
            background: state.color
        }}
      />
    )
}
```
- state에 넣어서 간단하게 사용가능

### static Context 이용
- 클래스형 컴포넌트에서 static context를 이용
- this.context를 조회하면 static context의 value를 가리키게 된다