[구글 데브](https://developer.chrome.com/docs/extensions/reference/storage/)를 참고한 글
## chrome.storage?
chrome에서 제공하는 storage API이며, local과 sync로 나뉜다.

Local vs Sync
- Local은 지역저장소 느낌, 구글 계정에 관계 없이 저장함
- Sync는 구글 계정에 맞춰서 저장됨
- 물론 당연하게도, Sync에는 어느정도의 성능 제한이 있지만 개인적으로 크게 불편하지 않은 정도
  
이와 관련한 정보들은 굳이 TIL에 적지 않아도 다른 곳에서 쉽게 찾을 수 있다.

좀 더 원론적인 얘기를 하자면, Sync로 설정하였는데 구글에 로그인이 되어있지 않으면 자동으로 Local로 저장하고 후에 구글 계정에 로그인이 되면 sync로 바꾸어준다.

---

또한, JSON형식을 따른다.  
- 즉 key-value의 형태로 데이터가 이루어져있다.
- get, set과 같이 이루어져있는데 set은 데이터를 추가 한다기 보다 "set" 하는 느낌이 강하다.
- array를 set하다가 애를 먹은 경험을 토대로 stackoverflow를 하나 첨부...
  -  [Saving array in chrome.storage](https://stackoverflow.com/questions/48781891/saving-array-in-chrome-storage)
  -  또한, 프로퍼티 동적 생성 ES6문법도 개발을 하며 정말 유용하였다.


## 참고한 자료
- [[확장프로그램 개발]데이터 저장하기](https://gyuyeon.tistory.com/6)
- [크롬 익스텐션: chrome.storage API](https://ohgyun.com/548)
