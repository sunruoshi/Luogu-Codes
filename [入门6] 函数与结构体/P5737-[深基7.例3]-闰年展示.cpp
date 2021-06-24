#include <iostream>
using namespace std;

bool isLeapYear(int d) {
	return d % 4 == 0 && d % 100 != 0 || d % 400 == 0;
}

int main() {
	int x, y, cnt = 0;
	cin >> x >> y;
	for (int i = x; i <= y; i++) {
		if (isLeapYear(i))
			cnt++;
	}
	cout << cnt << endl;
	for (int i = x; i <= y; i++) {
		if (isLeapYear(i))
			cout << i << ' ';
	}
	return 0;
}