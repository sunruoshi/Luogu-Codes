#include <cstdio>

int main() {
	int n, x = 0, y = 0, dir = 0;
	int dirs[4][2] = {
		{0,  1},
		{1,  0},
		{0,  -1},
		{-1, 0}
	};
	scanf("%d", &n);
	int m[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			m[i][j] = 0;
		}
	}
	for (int i = 1; i <= n * n; ++i) {
		m[x][y] = i;
		int nx = x + dirs[dir % 4][0], ny = y + dirs[dir % 4][1];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || m[nx][ny] != 0)
			dir++;
		x += dirs[dir % 4][0];
		y += dirs[dir % 4][1];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%3d", m[i][j]);
		}
		printf("\n");
	}
	return 0;
}
