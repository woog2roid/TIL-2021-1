//트리
//4803

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void plus(int a, int b);
int find(int a);
int unionFind[501];

int main(void) {
	int cnt = 1;
	int res = 0;
	while (1) {
		int n, m;	scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)	break;
		for (int i = 0; i < n; i++) unionFind[i] = i;
		for (int i = 0; i < m; i++) {
			int a, b;	scanf("%d %d", &a, &b);
			plus(a, b);
		}

		for (int i = 0; i <= n; i++) {
			if (unionFind[i] == i) {
				res++;
			}
		}
		
		printf("Case %d: ", cnt);
		switch(res) {
		case 0:
			printf("No trees.");
			break;
		case 1:
			printf("There is one tree.");
			break;
		default:
			printf("A forest of %d trees.", res);
			break;
		}
		printf("\n");

		cnt++; res = 0;
	}
}

void plus(int a, int b) {
	int A = find(a);
	int B = find(b);
	if (A == B) {
		unionFind[A] = -1;
	}
	else if(A < B){
		unionFind[B] = A;
	}
	else {
		unionFind[A] = B;
	}
}
int find(int a) {
	while (1) {
		int root = unionFind[a];
		if (root == a || root == -1) {
			return root;
		}
		a = root;
	}
}