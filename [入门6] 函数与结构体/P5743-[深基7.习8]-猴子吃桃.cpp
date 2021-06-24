#include <iostream>
using namespace std;

int sum = 1;

void eat(int n) {
	if (n == 1)
		return;
	sum = (sum + 1) * 2;
	eat(n - 1);
}

int main() {
	int n;
	cin >> n;
	eat(n);
	cout << sum;
	return 0;
}