[Google Developers](https://developer.chrome.com/docs/extensions/mv2/getstarted/)를 참고하여 정리한 글.

## mainfest.json
- 기본적인 정보와 기능을 정의함
- 모든 확장 프로그램은 manifest.json이 필수임

Google Developers Example Manifest
```json
{
  "name": "Getting Started Example",
  "version": "1.0",
  "description": "Build an Extension!",
  "manifest_version": 2
}
```
과 같은 형태로 기본적인 manifest.json을 완성할 수 있다.
- 물론 실제로 크롬에서 실행하면 icon을 추가하지 않아서 기본 아이콘이 나올 것이고, 아무런 기능도 없을 것이다.

> 크롬 확장 프로그램 설치하는 법
> 1. chrome://extensions
> 2. 개발자 모드를 킨다.
> 3. 확장 프로그램을 로드한다.

## Add instructions
- extension을 만들었지만 아무런 기능도 없다.
  - background script를 도입해서 instruction을 추가해야한다.
  - 물론, 이 backgournd script도 manifest.json에 추가해야한다.

JSON
```json
{
  "name": "Getting Started Example",
  "version": "1.0",
  "description": "Build an Extension!",
  "permissions": ["storage"],
  "background": {
    "scripts": ["background.js"],
    "persistent": false
  },
  "manifest_version": 2
}
```
background.js
```javascript
chrome.runtime.onInstalled.addListener(function() {
  chrome.storage.sync.set({color: '#3aa757'}, function() {
    console.log("The color is green.");
  });
});
```
- background에 scripts를 추가하였다.
- API를 이용하는 경우에 permission에 추가해주어야함.
  - backgorund.js에 runtime.onInstalled에 대한 수신이벤트를 작성하는 것으로 시작됨
  - onInstalled 리스너 안에서 storage API를 이용해서 값을 설정했음

## Introduce a user interface 
- 여러가지 형태의 UI 중 popup을 이용할 것임
- html로 작성해주고, json에 page_action -> default_popup 에 작성해주자

HTML
```html
<!DOCTYPE html>
<html>
  <head>
    <style>
      button {
        height: 30px;
        width: 30px;
        outline: none;
      }
    </style>
  </head>
  <body>
    <button id="changeColor"></button>
  </body>
</html>
```
JSON
```json
{
  "name": "Getting Started Example",
  "version": "1.0",
  "description": "Build an Extension!",
  "permissions": ["storage"],
  "background": {
    "scripts": ["background.js"],
    "persistent": false
  },
  "page_action": {
    "default_popup": "popup.html",
    "default_icon": {
      "16": "images/get_started16.png",
      "32": "images/get_started32.png",
      "48": "images/get_started48.png",
      "128": "images/get_started128.png"
    }
  },
  "icons": {
    "16": "images/get_started16.png",
    "32": "images/get_started32.png",
    "48": "images/get_started48.png",
    "128": "images/get_started128.png"
  },
  "manifest_version": 2
}
```
page_action과 browser_action은 거의 동일하다고 생각하면 되는데, 확장 프로그램이 동작하는 대상 페이지가 분명하면 page_action을 사용함

- default_icon에는 브라우저에 표시되는 아이콘이 적혀있음
- icon은 확장 관리 페이지, 즐겨찾기 등 다른 곳에도 표시되는데 이는 "icons"에 들어감

## Give users options
- 우클릭했을 때, "옵션" 부분을 의미함
- manifest.json에 ```"options_page": "options.html"```을 통해 option을 추가할 수 있음


