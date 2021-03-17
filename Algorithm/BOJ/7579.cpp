//앱
//https://www.acmicpc.net/problem/7579

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int N, M;
int m[100], c[100];
//int dp[10000000][100] (배열의 최대값을 넘는다 X)
int dp[10001];
//비용을 dp로 잡아서, 비용이 얼마 일때 그 최대로 만들어 낼 수 있는 메모리를 계산한다.
int main(void) {
	scanf("%d %d", &N, &M);
	int sum = 0;
	for (int i = 0; i < N; i++)	scanf("%d", &m[i]);
	for (int i = 0; i < N; i++) {
		scanf("%d", &c[i]);
		sum += c[i];
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = sum; j >= c[i]; j--) {
			dp[j] = max(dp[j], dp[j - c[i]] + m[i]); //현재 cost에서 최대로 확보할수있는 메모리
		}
	}

	for (int i = 0; i <= sum; i++) {
		if (dp[i] >= M) {
			printf("%d", i);
			return 0;
		}
	}
}