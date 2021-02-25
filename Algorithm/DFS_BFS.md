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
	while (!q.empty())
	{
		int curr = q.front();
		printf("%d ", curr);
		visited[curr] = 1;
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
- 이 정도면 다시 이거 보면 뭐 다 알아보겠지 뭐...?