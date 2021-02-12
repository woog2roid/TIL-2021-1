## npm(Node Pacakage Manager)
- 모든 기능을 다 구현하기에는 벅차니, 오픈소스 모듈을 올리는 곳
  - npm에 업로드된 노드 모듈을 패키지라고 부름
- 패키지들은 의존관계가 있는데, 예를들어 express만 설치하여도 다른 패키지들이 여러 개가 들어오는데 이는 express가 이용한 패키지들이다. 이러한 관계를 의존관계라 한다. 
  - node_modules에 설치한 패키지들이 들어간다.

> react에서 자주 보던 __yarn__ 은 npm의 대체자로 페이스북이 내놓은 패키지 매니저이다. 페이스북 진영의 라이브러리, 프레임워크를 이용할 때 자주 볼 수 있다.

## package.json
설치한 패키지의 버전을 관리하는 파일이 package.json이다

package.json이 필요한 이유?
- 서비스를 위해 패키지를 추가하다 보면 수십 수백의 패키지를 이용하게 된다.
- 이러한 패키지는 고유의 버전이 있으므로 이를 기록해야한다.
- 이러한 버전을 관리하는 파일이 package.json이다.

package.json의 주요 포인트들
- package name: 패키지 이름
- version: 패키지 버전
- entry point: 자바스크립트 실행 파일 진입점. 마지막으로 module.exports를 하는 파일. package.json의 main 속성에 저장된다/
- test command: 코드를 테스트할 때 입력할 명령어
- git repository: 코드를 저장해둔 깃 저장소 주소 (후에 문제가 생기면 문제 제기를 하거나 코드 수정본을 올릴 수 있도록)
- keywords: npm 고싱 홈페이지에서 이 패키지를 찾기 쉽게함
- licnese: 패키지 라이센스

package-lock.json: 패키지를 설치 수정 삭제할 때마다 패키지들 간의 내부 의존 관계가 이 파일에 저장된다.

## 패키지 버전
Npm은 SemVer(Semantic Versioning/ 유의적 버전)을 따른다. 
- SemVer은 1.16.1과 같이 세 자리로 구성된 버전 규칙이다.
- Major(첫 째 자리): 하위 호환이 되지 않는 변경 사항
- Minor(둘 째 자리): 하위 호환이 되는 변경 사항
- Patch(셋 째 자리): 간단한 버그 수정

