## 백트래킹이 뭐지?
딱히 어려운 점은 없고, 여러 경우의 수를 탐색할 때 (보통은 재귀/Dfs/스택구조)로 탐색함), 유망한 노드만을 탐색하여 효율적으로 탐색하는 방법.

포인트
- 직접 탐색을 하기 전에, 유망한지(promising) 체크를 하고 넣는다.
	- N퀸을 풀 때, (0,0) 다음에 (1,0) 즉 바로 밑 자리를 검사하여서 스택에 넣지않도록 배제하는 것. __[어찌보면 상당히 당연하다.]__

## 풀어본 문제들
[N퀸](https://www.acmicpc.net/problem/9663): [코드](https://github.com/woog2roid/PS-in-army.../blob/main/9663.cpp)  
- 유명한 문제라 이미 1차원 배열로 풀 수 있음을 알고 시작했지만, 생각보다 어렵지 않게 풀렸던 문제

[암호만들기](https://www.acmicpc.net/problem/1759): [코드](https://github.com/woog2roid/PS-in-army.../blob/main/1759.cpp)  
- 재귀적으로 쭈욱 res배열에 넣어주면 풀리는 쉬운 문제

[N과 M (1)](https://www.acmicpc.net/problem/15649):[코드](https://github.com/woog2roid/PS-in-army.../blob/main/15649.cpp)  
[N과 M (3)](https://www.acmicpc.net/problem/15651):[코드](https://github.com/woog2roid/PS-in-army.../blob/main/15651.cpp)
- 사실상 백트래킹이라기 보다 간단한 순열, 조합 만들기 문제... 재귀로 간단히 풀린다.

[스타트와 링크](https://www.acmicpc.net/problem/14889):[코드](https://github.com/woog2roid/PS-in-army.../blob/main/14889.cpp)  
- 절반만 뽑으면 나머지 절반은 team2에 넣으면 된다는 아이디어를 어떻게 구현할지 고민하다가 결국 그냥 수학적으로 풀어버렸다 --> 한명을 team1에 박아놓고 시작하면 정확히 절반임.
	- 그 이후는 오름차순으로 순열을 돌렸다.
- team의 능력치 계산에서 for문을 생각없이 N^2으로 돌렸다가 점수가 x2가 되서 나오는 실수가 있었는데, 테케 돌려보면서 금방 알아차려서 다행이었다...