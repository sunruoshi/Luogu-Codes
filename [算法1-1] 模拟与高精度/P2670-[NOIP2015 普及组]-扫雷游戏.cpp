#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	char mat[n][m];
	int dirs[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> mat[x][y];
			if (mat[x][y] == '?')
				mat[x][y] = '0';
		}
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (mat[x][y] != '*') {
				for (int i = 0; i < 8; i++) {
					int nx = x + dirs[i][0], ny = y + dirs[i][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == '*') {
						mat[x][y] = (mat[x][y] - '0') + 1 + '0';
					}
				}
			}
			cout << mat[x][y];
		}
		cout << endl;
	}
	return 0;
}