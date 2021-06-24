#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long sum = 0;
	int arr[30], i = 0;
	while (cin >> arr[i++]);
	for (int j = 0; j < i - 1; j++) {
		sum += arr[j];
	}
	sum *= pow(2, i - 2);
	cout << sum;
	return 0;
}