//숨바꼭질 3
//https://www.acmicpc.net/problem/13549

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <deque>
using namespace std;

#define MAX 100001
int cnt[MAX];
bool visited[MAX];

int main(void) {
	int start, end;
	scanf("%d %d", &start, &end);

	//advanced BFS
	deque<int> dq;
	dq.push_front(start);
	while (!dq.empty()) {
		int x = dq.front();
		dq.pop_front();
		visited[x] = 1;
		if (x == end) {
			printf("%d", cnt[end]);
			return 0;
		}

		//teleport
		int teleport = x * 2;
		if (teleport < MAX && !visited[teleport]) {
			cnt[teleport] = cnt[x];
			dq.push_front(teleport);
			visited[teleport] = 1;
		}

		//add 
		int add = x + 1;
		if (add < MAX && !visited[add]) {
			cnt[add] = cnt[x] + 1;
			dq.push_back(add);
			visited[add] = 1;
		}

		//sub
		int sub = x - 1;
		if (sub > -1 && !visited[sub]) {
			cnt[sub] = cnt[x] + 1;
			dq.push_back(sub);
			visited[sub] = 1;
		}
	}
}