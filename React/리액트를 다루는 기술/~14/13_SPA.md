## SPA
single Page Application
- 서버에서 사용자에게 제공하는 페이지는 한 종류이지만, 여러가지 주소 상태에 따라 다양한 화면을 보여줄 수 있음
- 뷰 렌더링을 사용자의 브라우저가 담당하고, 업데이트가 필요한 부분은 JS를 이용해서 업데이트함
  - 점점 사이트들의 정보량이 많아지기에, 여러페이지를 보내주고, 서버측에서 모든 뷰를 담당하면 힘들어서... 
- 규모가 너무 커지면 JS 파일이 커져서 초기 구동시에 힘들 수도 있음
  - 코드 스플리팅을 이용해 해결가능

## 라우팅
> 다른 주소에 다른 화면을 보여주는 것을 라우팅이라고 한다.
- 물론, 리액트는 View만 담당하는 라이브러리로 라우팅 기능이 따로 내장되어있지 않아서, 따로 설치해서 사용해야함
  - 리액트 라우터를 보통 이용함

## react-router: 기본
- react-router-dom에 내장되어있는 BrowserRouter라는 컴포넌트를 사용하여 감싸면 된다.
  - 웹앱에서 HTML 5의 History API를 이용해서 새로고침하지 않고도 주소를 변경
  - 주소에 관련된 정보를 props로 쉽게 조회하거나 사용할 수 있도록 해준다.
```javascript
import {BrowserRouter} from 'react-router-dom'

ReactDom.render(
    <BrowserRouter>
        <App/>
    </BrowserRouter>,
    document.getElementById('root')
);

serviceWorker.unregister();
```
- src/index.js에서 \<BrowserRouter\>라는 컴포넌트로 감싸기 가능
- Histroy API를 이용해서 새로고침 없이 주소를 변경하고 현재 주소에 관련한 정보를 props로 쉽게 조회

## react-router: 페이지 만들기
App.js
```javascript
// Home.js와 About.js는 이미 만들었다고 가정
import React from 'react';
import { Route } from 'react-router-dom';
import About from './About';
import Home from './Home';

const App = () => {
    return (
        <div>
            <ul>
                {/*<Link to = "주소"> 내용 </Link>*/}
                <li>    <Link to="/">Home</Link>    </li>
                <li>    <Link to="/about">About</Link>    </li>
            </ul>
            {/*<Route path = "주소규칙" component={보여줄 컴포넌트} />*/}
            <Route path="/" component={Home} exact={true} />
            <Route path="/about" component={About} />
        </div>
    )
}
```
- exact=ture는 무슨 의미?
  - exact=true가 없으면 About을 눌렀을 떄 Home도 같이 나옴,,, Home의 path도 만족하기 때문. 그래서 넣어주는 것
- Link 말고 HTML에서 쓰던 a를 쓰면 안되나?
  - a 태그는 새로 불러오는 과정에서 가지고 있던 상태들을 모두 날려버린다.

여러개 한번에 쓰고 싶으면,
```javascript
<Route path={['/about', '/info']}> component={About} />
```

## URL 파라미터와 쿼리
- URL 파라미터: /propfile/velopert
  - 특정 ID나 이름 조회
- URL 쿼리: /about?details=true
  - 검색 or 옵션 전달

__파라미터의 유동적인 username을 넣을 때 props로 받아와서 조회해보기__
```javascript
    //...
    const data = {
        velopert: {
            name:...,
        }
        woog2roid: {
            name:...,
        }
    };

    const Profile = ({match})=> {
        const {username} = match.params;
        //URL 파라미터의 값을 match.params로 받아서...
        const profile = data[username];
        //ES6 구조 분해 할당...
        if (!profile) { return <div>No user</div>; }
        return (
            ....
        )
    }
```
와 같이 조회하면 된다.

__URL 쿼리를 props로 받아오기__
```javascript
/*
 http://localhost:3000/about?detail=true
 {
     "pathname": "/about",
     "search": "?detail=true",
     "hash": ""
 }
 */
import qs from 'qs';

const About = ({location}) => {
    const query = qs.parse(location.search, {
        ignoreQueryPrefix: true // 문자열 맨 앞의 ? 생략
    });
    const showDetail = querty.detail === 'true';
    return (
        //something nice
    );
};
```
와 같이 조회하면 된다.
- 객체가 지닌 값중에 search를 확인하면 된다.
- qs라는 라이브러리를 이용해서 쿼리 문자열을 객체로 변환한다.
  - 쿼리 문자열을 객체로 변환하는 과정에서 결과값은 언제나 문자열임...
  - 즉, parseInt 메서드나 "true"처럼 잘 처리해야함 문자열로...