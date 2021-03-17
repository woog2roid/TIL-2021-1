//DFS와 BFS
//https://www.acmicpc.net/problem/1260

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <queue>
#include <string.h>
using namespace std;

bool map[1001][1001];
bool visited[1001];

void DFS(int start, int size);
void BFS(int start, int size);

int main(void)
{
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		map[s][e] = 1;
		map[e][s] = 1;
	}

	DFS(v, n);
	printf("\n");
	memset(visited, 0, sizeof(visited));
	BFS(v, n);
	return 0;
}

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