#include <iostream>
using namespace std;

int n, k, ans, arr[20];

bool isPrime(int d) {
    if (d < 2) return false;
    if (d % 2 == 0 && d != 2) return false;
    for (int i = 3; i * i <= d; i += 2) {
        if (d % i == 0) return false;
    }
    return true;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += arr[i];
                cnt++;
            }
        }
        if (cnt == k) ans += isPrime(sum);
    }
    cout << ans;
    return 0;
}
