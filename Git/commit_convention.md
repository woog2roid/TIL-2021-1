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
   - 그래야 log를 가독성이 좋다.
2. 제목은 영문 기준 50자 이내로
3. 제목 첫글자를 대문자로
4. 제목 끝에 . 금지
5. 제목은 명령조로
   - git의 기본 commit이 "Update README.md"와 같이 명령조이기 때문에 git의 built-in convention을 따른다는 의미임
6. 본문은 영문 기준 72자마다 줄 바꾸기
7. 본문은 어떻게보다 무엇을, 왜에 맞춰 작성하기


[[Git] 커밋 메시지 규약 정리 (the AngularJS commit conventions)](https://velog.io/@outstandingboy/Git-%EC%BB%A4%EB%B0%8B-%EB%A9%94%EC%8B%9C%EC%A7%80-%EA%B7%9C%EC%95%BD-%EC%A0%95%EB%A6%AC-the-AngularJS-commit-conventions): Angular commit convention을 잘 번역한 글이다.

오픈 소스 프로젝트들의 커밋 메세지에  
```
feat : 새로운 기능 추가
fix : 버그 수정
docs : 문서 관련
style : 스타일 변경 (포매팅 수정, 들여쓰기 추가, …)
refactor : 코드 리팩토링
test : 테스트 관련 코드
build : 빌드 관련 파일 수정
ci : CI 설정 파일 수정
perf : 성능 개선
chore : 그 외 자잘한 수정
```
이와 같은 것들이 앞에 나오는 경우가 있는데, 이렇게 참고해보면 좋을듯하다.
[여기](https://github.com/angular/angular/commits/master)에서 잘 정돈된 커밋 메세지들을 볼 수 있다.

## 참고자료
[좋은 git 커밋 메시지를 작성하기 위한 7가지 약속](https://meetup.toast.com/posts/106)  
[[Git] 커밋 메시지 규약 정리 (the AngularJS commit conventions)](https://velog.io/@outstandingboy/Git-%EC%BB%A4%EB%B0%8B-%EB%A9%94%EC%8B%9C%EC%A7%80-%EA%B7%9C%EC%95%BD-%EC%A0%95%EB%A6%AC-the-AngularJS-commit-conventions): Angular commit convention을 잘 번역한 글  
[좋은 git commit 메시지를 위한 영어 사전](https://blog.ull.im/engineering/2019/03/10/logs-on-git.html): 커밋 메세지를 적는데 도움이 많이 될듯 하다.  
[깃(Git) 커밋 가이드](https://tech.10000lab.xyz/git/git-commit-discipline.html#%EC%BB%A4%EB%B0%8B%EC%9D%80-%EA%BC%AD-%EB%85%BC%EB%A6%AC%EC%A0%81%EC%9C%BC%EB%A1%9C-%EA%B5%AC%EB%B6%84%EB%90%98%EB%A9%B0-%EC%9D%BC%EA%B4%80%EC%84%B1-%EC%9E%88%EC%96%B4%EC%95%BC%ED%95%A9%EB%8B%88%EB%8B%A4): 커밋의 단위에 관해