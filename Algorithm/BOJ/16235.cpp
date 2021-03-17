// 나무 재테크
// https://www.acmicpc.net/problem/16235

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdbool.h>
using namespace std;

int rMove[8] = {-1, -1, -1,	0, 0, 1, 1, 1};
int cMove[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool chk(int r, int c, int n) {
	return (0 < r && r <= n) && (0 < c && c <= n);
}

//1~10
vector<int> map[11][11];
int curr[11][11];
int add[11][11];
int die[11][11];

int main(void) {
	//입력
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &add[i][j]);
			curr[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		int r, c, age;
		scanf("%d %d %d", &r, &c, &age);
		map[r][c].push_back(age);
	}


	//풀이
	for (int i = 0; i < k; i++) {
		//정렬
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				sort(map[i][j].begin(), map[i][j].end());
			}
		}
		//.봄
		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= n; c++) {
				for (int k = 0; k < map[r][c].size(); k++) {
					if (map[r][c].at(k) <= curr[r][c]) {
						curr[r][c] -= map[r][c].at(k);
						map[r][c].at(k)++;
					}
					else {
						for(int j = k; j< map[r][c].size(); j++) die[r][c] += (map[r][c].at(j) / 2);
						map[r][c].erase(map[r][c].begin() + k, map[r][c].begin()+map[r][c].size());
						continue;
					}
				}
			}
		}
		//여름
		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= n; c++) {
				curr[r][c] += die[r][c];
				die[r][c] = 0;
			}
		}
		//가을
		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= n; c++) {
				for (int k = 0; k < map[r][c].size(); k++) {
					if (map[r][c].at(k) % 5 == 0) {
						for (int i = 0; i < 8; i++) {
							if (chk(r + rMove[i], c + cMove[i], n)) {
								map[r + rMove[i]][c + cMove[i]].push_back(1);
							}
						}
					}
				}
			}
		}
		//겨울
		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= n; c++) {
				curr[r][c] += add[r][c];
			}
		}
	}


	//출력
	int res = 0;
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			res += map[r][c].size();
		}
	}
	printf("%d", res);
	return 0;
}