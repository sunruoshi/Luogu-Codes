#include <iostream>
#include <algorithm>
using namespace std;

int n, ans, maxa, arr[10001], mod = 1000000007;

int C2(int n) {
    return (n * (n - 1) / 2) % mod;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        maxa = max(maxa, d);
        arr[d]++;
    }
    for (int i = 1; i <= maxa; i++) {
        for (int j = i; j <= maxa; j++) {
            if (i == j)  ans = (ans + (C2(arr[i]) * C2(arr[i + j]))) % mod;
            else ans = (ans + ((arr[i] * arr[j]) % mod * C2(arr[i + j])) % mod) % mod;
        }
    }
    cout << ans;
    return 0;
}
