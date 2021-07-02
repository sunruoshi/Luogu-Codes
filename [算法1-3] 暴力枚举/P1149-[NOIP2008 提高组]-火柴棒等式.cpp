#include <bits/stdc++.h>
using namespace std;

int n, p, ans, temp[3], num[1000] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int cost(int d) {
    if (num[d]) return num[d];
    else {
        int t = 0, n = d;
        while (n > 0) {
            t += num[n % 10];
            n /= 10;
        }
        num[d] = t;
        return t;
    }
}

void dfs(int sum) {
    if (sum >= n - 4 || p == 3) {
        if (p == 3 && temp[0] + temp[1] == temp[2] && sum == n - 4) ans++;
        return;
    }
    for (int i = 0; i < 1000; i++) {
        sum += cost(i);
        temp[p++] = i;
        dfs(sum);
        temp[p--] = 0;
        sum -= cost(i);
    }
}

int main() {
    scanf("%d", &n);
    dfs(0);
    printf("%d", ans);
    return 0;
}
