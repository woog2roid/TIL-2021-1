[Google Developers](https://developer.chrome.com/docs/extensions/mv2/overview/)를 참고하여 정리한 글.

## extensions
- Extensions are small software programs that customize the browsing experience

## manifest.json
```json
{
  "name": "Hello Extensions",
  "description" : "Base Level Extension",
  "version": "1.0",
  "manifest_version": 2,
  "browser_action": {
    "default_popup": "hello.html",
    "default_icon": "hello_extensions.png"
  },
  "commands": {
    "_execute_browser_action": {
      "suggested_key": {
        "default": "Ctrl+Shift+F",
        "mac": "MacCtrl+Shift+F"
      },
      "description": "Opens hello.html"
    }
  }
}
```
- browser_action: 브러우저에 생기는 extension의 이밎, 페이지 등을 설정함
  - default_popup: 표시할 팝업 화면
  - default_image: 확장 프로그램 아이콘
- commands: 키보드 shortcut을 지정하기 위함

## hello.html
```html
<html>
  <body>
    <h1>Hello Extensions</h1>
  </body>
</html>
```
- 작동하는 지 확인만 하기 위한 기본 예제이므로...