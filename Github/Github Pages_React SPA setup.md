### github pages를 이용해서 react SPA 배포하기, (404error 해결)

__github pages에서 404가 뜨는 이유__
1. 모든 요청에 대해서 index.html을 반환해야한다.
2. 우리는 github pages의 로직은 건들 수 없다. 
3. 결국 "/"이 아닌 다른 url로부터의 직접적인 요청은 404error가 뜬다.

__해결법__
1. public 폴더에 404.html을 생성해서 404error 페이지를 띄워줄 수 있다.
2. 이 점을 이용해서, 404.html에서 index.html로 직접 보내주는 스크립트를 짠다.


- 물론 SEO(검색엔진 최적화)가 망가진다는 단점이 있긴하다...

참고  
- [Github Page로 React SPA 배포하기 (ft. React Router)](https://velog.io/@ausg/gh-pages-react-router)
- [[React] GitHub Pages에 React App(SPA) 호스팅 하기 / 404.html, index.html 코드 포함](https://iamsjy17.github.io/react/2018/11/04/githubpage-SPA.html)	