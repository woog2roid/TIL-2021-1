기초로 돌아가서 천천히 정리하자는 생각에 써보는 글...  
나중에 PS를 한동안 안했다가 다시 하려고 하면 또 여기서부터 다시 헤맬까봐...  
그래도 BFS DFS정도만 해도 왠만한 기본문제는 다 푸니까...

__코드는 [DFS와 BFS(백준 1260)](https://github.com/woog2roid/Problem-Solving/blob/main/1260.cpp)를 이용함__

## DFS
```C++
void DFS(int start, int size)
{
	visited[start] = 1;
	printf("%d ", start);

	for (int i = 1; i <= size; i++)
	{
		if (map[start][i] == 1 && visited[i] == 0)
		{
			DFS(i, size);
		}
	}

	return;
}
```
포인트
- 파라미터로 현재 node를 건네준다
- 당연하지만 visited를 체크해주어야 간 곳을 다시 안간다.

## BFS
```C++
void BFS(int start, int size)
{
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	while (!q.empty())
	{
		int curr = q.front();
		printf("%d ", curr);
		q.pop();
		for (int i = 1; i <= size; i++)
		{
			if (map[curr][i] != 0 && visited[i] == 0)
			{
				q.push(i);
				visited[i] = 1;
			}
		}
	}
	return;
}
```
포인트
- push를 하면서 동시에 visited 체크를 해주어야 메모리가 넘치지 않는다.
  - pop을 하면서 방문 체크를 하면 여러번 체크되는 런타임에러가 발생한다...
  - 그냥 q.push()하고 visited는 세트라고 생각하기...

## 정리
- 둘다 visited 처리 꼼꼼하게 하기
- BFS는 push와 동시에 visited처리를 해주어야 런타임에러가 안뜸
- __추가: 그냥 DFS고 BFS고 가장 빠르게, visited 처리를 해주는게 맞음. 넣자마자 처리해준다고 생각하자.__
	- 보면 q.push(start); 다음에 visited[start] = 1; 처럼 그냥 최대한 큐나 스택에 넣자마자 처리해준다고 생각하면 됨.
	- DFS(스택)의 경우에도 재귀에 들어가자마자 1 처리해주는 것과 동일
	
## 풀어본 문제들
전체적으로 생 DFS와 BFS는 기본이기도 하고, 나름 문제들을 많이 풀어왔기 때문에 (물론 다른 알고리즘보다, 순전히 나의 기준이다.) 어렵지 않았다.
정말 문제들을 보자마자 구현이 바로바로 떠오르는 어... 정말 구현문제들에 가까운 문제들이었다.
- 그래도 check 함수는 꼭꼭 잘 체크해보도록 하자.
	- BFS, DFS는 nextX, nextY, check 함수가 너무 자주 쓰이는데 check함수에서 실수를 자주 하더라...
- 틀렸다고 뜬다면 visited와 map을 확인해보자

[단지번호 붙히기](https://github.com/woog2roid/PS-in-army.../blob/main/2667.cpp)  
그래도, 오랜만에 푸니까 헷갈렸었는데, DFS나 BFS 자체보다는 _break와 continue_ 를 헷갈리고 _sort의 범위_ 를 헷갈렸다...

[나이트의 이동](https://github.com/woog2roid/PS-in-army.../blob/main/7562.cpp)  
정말 기본적인 문제이고, 여러번 반복하는 과정에서 초기화를 까먹어서 몇분 돌아갔지만 금방 푼 문제였다.

[토마토](https://github.com/woog2roid/PS-in-army.../blob/main/7569.cpp)  
x,y가 아니라 그냥 문제에서 주는 변수들로 써야겠다고 생각하게 한 문제,,, 3차원쯤 되고 하니까 ijk로는 헷갈리고 mnh와 xyz가 겹치니 조금 헷갈렸다.
그래도 문제는 변수명이 아니라 check함수에 있었긴 했다.

[미로 탈출하기](https://www.acmicpc.net/problem/17090):[코드](https://github.com/woog2roid/PS-in-army.../blob/main/17090.cpp)  
왜 DP로 분류되었을까 싶었는데, 메모를 하는 것이 DP라면 DP일수도...?  
DFS로 쭈욱 탐색하고 재귀적으로 끝부터 돌아오는 방식을 택했다.  
그 이후에는 이미 탐색한 곳이면 탐색하지 않고 배열에 값을 넣어주었다.  
이것 때문에 DP로 분류된 듯 하다.