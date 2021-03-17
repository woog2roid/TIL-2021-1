//미세먼지 안녕!
//https://www.acmicpc.net/problem/17144

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int map[50][50];
int cpy[50][50];
int cleaner[2];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

bool check(int row, int col, int r, int c) {
	return (0 <= row && row < r) && (0 <= col && col < c) && (map[row][col] != -1);
}

int spread(int row, int col, int r, int c);
int cleanUp(int row, int r, int c);
int cleanDown(int row, int r, int c);

int main(void) {
	//입력
	int r, c, t;
	scanf("%d %d %d", &r, &c, &t);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < r; i ++ ) {
		if (map[i][0] == -1) {
			cleaner[0] = i;
			cleaner[1] = cleaner[0] + 1;
			break;
		}
	}
	
	for (int i = 0; i < t; i++) {
		memcpy(cpy, map, sizeof(map));
		//확산
		for (int row = 0; row < r; row++) {
			for (int col = 0; col < c; col++) {
				if (cpy[row][col] != 0 && cpy[row][col] != -1) {
					spread(row, col, r, c);
				}
			}
		}
		//청정
		cleanUp(cleaner[0], r, c);
		cleanDown(cleaner[1], r, c);
	}

	//출력
	int res = 0;
	for (int i = 0; i < r; i ++ ) {
		for (int j = 0; j < c; j++) {
			res += map[i][j];
		}
	}

	printf("%d", res + 2);
	return 0;	
}

int spread(int row, int col ,int r, int c) {
	int vol = cpy[row][col] / 5;

	for (int i = 0; i < 4; i++) {
		if (check(row + dr[i], col + dc[i], r, c)) {
			map[row + dr[i]][col + dc[i]] += vol;
			map[row][col] -= vol;
		}
	}

	return 0;
}

int cleanUp(int row, int r, int c) {
	int tmpBefore = 0;
	int tmpAfter = 0;
	//>
	for (int i = 1; i < c; i++) {
		tmpAfter = map[row][i];
		map[row][i] = tmpBefore;
		tmpBefore = tmpAfter;
	}
	//^
	for (int i = row - 1; i >= 0; i--) {
		tmpAfter = map[i][c - 1];
		map[i][c - 1] = tmpBefore;
		tmpBefore = tmpAfter;
	}
	//<
	for (int i = c - 2; i >= 0; i--) {
		tmpAfter = map[0][i];
		map[0][i] = tmpBefore;
		tmpBefore = tmpAfter;
	}
	//v
	for (int i = 1; i < row; i++) {
		tmpAfter = map[i][0];
		map[i][0] = tmpBefore;
		tmpBefore = tmpAfter;
	}

	return 0;
}


int cleanDown(int row, int r, int c) {
	int tmpBefore = 0;
	int tmpAfter = 0;
	//>
	for (int i = 1; i < c; i++) {
		tmpAfter = map[row][i];
		map[row][i] = tmpBefore;
		tmpBefore = tmpAfter;
	}
	//v
	for (int i = row + 1; i < r; i++) {
		tmpAfter = map[i][c - 1];
		map[i][c - 1] = tmpBefore;
		tmpBefore = tmpAfter;
	}
	//<
	for (int i = c - 2; i >= 0; i--) {
		tmpAfter = map[r - 1][i];
		map[r - 1][i] = tmpBefore;
		tmpBefore = tmpAfter;
	}
	for (int i = r -  2; i > row; i--) {
		tmpAfter = map[i][0];
		map[i][0] = tmpBefore;
		tmpBefore = tmpAfter;
	}

	return 0;
}