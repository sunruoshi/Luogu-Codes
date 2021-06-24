#include <iostream>
using namespace std;

int prime[10000] = {2};

bool isPrime(int d) {
	for (int i = 2; i * i <= d; i++) {
		if (d % i == 0)
			return false;
	}
	return true;
}

void find(int d, int start) {
	int cur = start;
	while (prime[cur] < d) {
		if (prime[cur] + prime[start] == d) {
			cout << d << '=' << prime[start] << '+' << prime[cur] << endl;
			return;
		}
		cur++;
	}
	find(d, start + 1);
}

int main() {
	int n, idx = 1;
	cin >> n;
	for (int i = 3; i <= n; i += 2) {
		if (isPrime(i)) {
			prime[idx] = i;
			idx++;
		}
	}
	for (int i = 4; i <= n; i += 2) {
		find(i, 0);
	}
	return 0;
}