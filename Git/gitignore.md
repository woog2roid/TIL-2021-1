## gitignore 문법
|||  
|:---:|:---:|  
|#| #은 주석을 의미한다.|  
|*.a|확장자가 .a인 모든 파일을 무시한다.|  
|folder_name/|해당 폴더의 모든 파일을 무시한다.|  
|folder_name/*.a|해당 폴더의 확장자가 .a인 모든 파일을 무시한다.|  
|folder_name/**/*.a|해당 폴더를 포함한 하위 모든 폴더에서 .a인 모든 파일을 무시한다.|  
|/*.a|현재 폴더의 확장자가 .a인 모든 파일을 무시한다.|  


### 이미 stage에 올라간 파일들은?
.gitignore에 파일을 추가하기 전에 stage에 올라간 파일들은 캐시처리가 되어 기록에 남아있다. 이 경우 
```
git rm -r --cached  
혹은,  
git rm -r -f --cached
```
를 통해 캐시를 지워준 후 add 하면 ignore가 잘 되는 것을 확인할 수 있다.