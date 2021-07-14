혼자 이것저것 만들어보면서 만든 commit의 단위나 메세지들이 심하게 개판이라는 것을 깨달았다...

물론 혼자 버전관리를 하는 것이기 때문에 아직은 큰 일이 일어나진 않았지만, 협업을 대비해서 미리 커밋을 깔끔하게 쓰는 버릇을 들여야겠다. 그전에 어떻게 해야 깔끔한 커밋을 작성하는 지를 알아야겠지?

## 커밋의 단위
Each commit is a minimal coherent idea
- 논리적으로 구분되면 일관성있도록 할것
- 커밋은 최소 단위로 이루어져야 한다.

[깃(Git) 커밋 가이드](https://tech.10000lab.xyz/git/git-commit-discipline.html#%EC%BB%A4%EB%B0%8B%EC%9D%80-%EA%BC%AD-%EB%85%BC%EB%A6%AC%EC%A0%81%EC%9C%BC%EB%A1%9C-%EA%B5%AC%EB%B6%84%EB%90%98%EB%A9%B0-%EC%9D%BC%EA%B4%80%EC%84%B1-%EC%9E%88%EC%96%B4%EC%95%BC%ED%95%A9%EB%8B%88%EB%8B%A4)

## 커밋의 메세지 작성법
커밋 메세지를 영어로 작성할 때의 규칙  
~~한글로 작성할 때는 유도리 있게 잘 바꿔서 쓰자...~~

1. 제목과 본문을 한 줄 띄워 분리하기
   - 그래야 log의 가독성이 좋다.
2. 제목은 영문 기준 50자 이내로
3. 제목 첫글자를 대문자로
4. 제목 끝에 . 금지
5. 제목은 명령조로
   - git의 기본 commit이 "Update README.md"와 같이 명령조이기 때문에 git의 built-in convention을 따른다는 의미임
6. 본문은 영문 기준 72자마다 줄 바꾸기
7. 본문은 어떻게보다 무엇을, 왜에 맞춰 작성하기

## 커밋 태그.  
[협업을 위한 git 커밋컨벤션 설정하기](https://overcome-the-limits.tistory.com/entry/%ED%98%91%EC%97%85-%ED%98%91%EC%97%85%EC%9D%84-%EC%9C%84%ED%95%9C-%EA%B8%B0%EB%B3%B8%EC%A0%81%EC%9D%B8-git-%EC%BB%A4%EB%B0%8B%EC%BB%A8%EB%B2%A4%EC%85%98-%EC%84%A4%EC%A0%95%ED%95%98%EA%B8%B0)가 큰 도움이 되었다.
[Angular9 commit convention 원문](https://github.com/angular/angular/blob/master/CONTRIBUTING.md#type)

_기능_

- Feat: 새로운 기능을 추가할 경우  
- Fix: 버그를 고친 경우  
- Design: CSS 등 사용자 UI 디자인 변경  
- !BREAKING CHANGE: 커다란 API 변경의 경우  

_개선_

- !HOTFIX: 급하게 치명적인 버그를 고쳐야하는 경우  
- Style: 코드 포맷 변경, 세미 콜론 누락, 코드 수정이 없는 경우  
- Refactor: 프로덕션 코드 리팩토링  
- Comment: 필요한 주석 추가 및 변경
- perf: 성능을 향상시키는 코드 변경

_그 외_

- Docs: 문서를 수정한 경우  
- Test: 테스트 추가, 테스트 리팩토링(프로덕션 코드 변경 X)  
- Chore: 빌드 태스트 업데이트, 패키지 매니저를 설정하는 경우(프로덕션 코드 변경 X) 
- Rename: 파일 혹은 폴더명을 수정하거나 옮기는 작업만인 경우  
- Remove: 파일을 삭제하는 작업만 수행한 경우
- Build: 빌드 시스템과 dependencies에 영향을 미치는 변경(ex: npm)
- ci: ci 구성및 스크립트 변경


[여기](https://github.com/angular/angular/commits/master)에서 잘 정돈된 커밋 메세지들을 볼 수 있다.

## 참고자료
[협업을 위한 git 커밋컨벤션 설정하기](https://overcome-the-limits.tistory.com/entry/%ED%98%91%EC%97%85-%ED%98%91%EC%97%85%EC%9D%84-%EC%9C%84%ED%95%9C-%EA%B8%B0%EB%B3%B8%EC%A0%81%EC%9D%B8-git-%EC%BB%A4%EB%B0%8B%EC%BB%A8%EB%B2%A4%EC%85%98-%EC%84%A4%EC%A0%95%ED%95%98%EA%B8%B0)  
[좋은 git 커밋 메시지를 작성하기 위한 7가지 약속](https://meetup.toast.com/posts/106)  
[[Git] 커밋 메시지 규약 정리 (the AngularJS commit conventions)](https://velog.io/@outstandingboy/Git-%EC%BB%A4%EB%B0%8B-%EB%A9%94%EC%8B%9C%EC%A7%80-%EA%B7%9C%EC%95%BD-%EC%A0%95%EB%A6%AC-the-AngularJS-commit-conventions): Angular commit convention을 잘 번역한 글  
[좋은 git commit 메시지를 위한 영어 사전](https://blog.ull.im/engineering/2019/03/10/logs-on-git.html): 커밋 메세지를 적는데 도움이 많이 될듯 하다.  
[깃(Git) 커밋 가이드](https://tech.10000lab.xyz/git/git-commit-discipline.html#%EC%BB%A4%EB%B0%8B%EC%9D%80-%EA%BC%AD-%EB%85%BC%EB%A6%AC%EC%A0%81%EC%9C%BC%EB%A1%9C-%EA%B5%AC%EB%B6%84%EB%90%98%EB%A9%B0-%EC%9D%BC%EA%B4%80%EC%84%B1-%EC%9E%88%EC%96%B4%EC%95%BC%ED%95%A9%EB%8B%88%EB%8B%A4): 커밋의 단위에 관해