//가장 긴 바이토닉 부분 수열
//https://www.acmicpc.net/problem/11054

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[1000];
int incr[1000];
int decr[1000];
int res[1000];

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		incr[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && incr[i] < incr[j] + 1)  incr[i] = incr[j] + 1;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		decr[i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[i] && decr[i] < decr[j] + 1)  decr[i] = decr[j] + 1;
		}
	}

	int max = -1;
	for (int i = 0; i < n; i++) {
		res[i] = incr[i] + decr[i] - 1;
		if (max < res[i])	max = res[i];
	}


	printf("%d", max);
	return 0;
}