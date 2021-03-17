// 구간합 구하기 5
// https://www.acmicpc.net/problem/11660

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int map[1025][1025];
int dp[1025][1025];

int main(void) {
	int N, m;
	scanf(" %d %d", &N, &m);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dp[1][1] = map[1][1];
	for (int i = 1; i <= N; i++) {
		dp[1][i] = dp[1][i - 1] + map[1][i];
		dp[i][1] = dp[i - 1][1] + map[i][1];
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]);
	}

	return 0;
}