#include <iostream>
using namespace std;

int isPrime(int d) {
	if (d < 2)
		return 0;
	for (int i = 2; i * i <= d; i++) {
		if (d % i == 0)
			return 0;
	}
	return 1;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (isPrime(arr[i]))
			cout << arr[i] << ' ';
	}
	return 0;
}