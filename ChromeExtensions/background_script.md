## Background script vs Content script
- background script는 chrome://extension의 백그라운드에 로그가 찍힘
- content script는 크롬 익스텐션 화면의 개발자 도구에 로그가 찍힘

storage API 등 대부분의 chrome API 이용하는 액션들은 background script에서만 가능함
- content script에서 이벤트를 발생시키고 background script에서 받아서 실행하는 형태로 코딩
```javascript
// contentscript.js
chrome.runtime.sendMessage({action: "FINISH"}, function(response) {
    alert(response);
});

// background.js
chrome.runtime.onMessage.addListener(function (request, sender, sendResponse) {
    console.log(sender.tab ?
        "from a content script:" + sender.tab.url :
        "from the extension");
        //sender.tab은 tab ID를 의미함

    if (request.action === "FINISH")
        sendResponse({farewell: "goodbye"});
});
```
## manifest.json
```json
+   "background": {
+     "scripts": ["background.js"],
+     "persistent": false
+   },
```
persistent는 event pages를 의미한다.
- true라면 항상 돌아가는 background page이고, false라면 event 기반으로 돌아가는 event page가 된다. 
- 화면에서 돌아가는 webRequest를 받기 위해서는 true를 해야한다고 한다...


## 참고한 자료
- [Google Dev: background](https://developer.chrome.com/docs/extensions/mv2/background_pages/)
- [Google Dev: content scripts](https://developer.chrome.com/docs/extensions/mv2/content_scripts/)
- [Google Dev: content scripts 번역](https://qkqhxla1.tistory.com/857)
- [Chrome Extension 개발](https://tidyline.gitbook.io/today-i-learned/etc/chromeextension)
- [크롬 익스텐션: Background Pages 와 Event Pages](https://ohgyun.com/535)