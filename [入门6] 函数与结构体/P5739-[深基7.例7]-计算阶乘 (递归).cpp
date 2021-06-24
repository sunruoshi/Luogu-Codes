#include <iostream>
using namespace std;

int factorial(int d) {
	if (d == 0)
		return 1;
	return d * factorial(d - 1);
}

int main() {
	int n;
	cin >> n;
	cout << factorial(n);
	return 0;
}