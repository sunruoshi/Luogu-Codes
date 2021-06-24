#include <iostream>
using namespace std;

int m[1024][1024];

void remit(int l, int x, int y) {
	if (l == 1)
		return;
	for (int i = x; i < x + l / 2; i++) {
		for (int j = y; j < y + l / 2; j++) {
			m[i][j] = 0;
		}
	}
	remit(l / 2, x + l / 2, y);
	remit(l / 2, x, y + l / 2);
	remit(l / 2, x + l / 2, y + l / 2);
}

int main() {
	int n, l = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		l *= 2;
	}
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			m[i][j] = 1;
		}
	}
	remit(l, 0, 0);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			cout << m[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}