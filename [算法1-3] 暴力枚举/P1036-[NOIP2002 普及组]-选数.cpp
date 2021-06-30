#include <bits/stdc++.h>
using namespace std;

int n, k, arr[20];

bool isPrime(int d) {
    if (d < 2) return false;
    if (d % 2 == 0 && d != 2) return false;
    for (int i = 3; i * i <= d; i += 2) {
        if (d % i == 0) return false;
    }
    return true;
}

int dfs(int start, int sum, int cnt) {
    if (cnt == k) return isPrime(sum);
    int ans = 0;
    for (int i = start; i < n; i++) {
        ans += dfs(i + 1, sum + arr[i], cnt + 1);
    }
    return ans;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << dfs(0, 0, 0);
    return 0;
}
