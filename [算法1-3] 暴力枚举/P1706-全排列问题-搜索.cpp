#include <bits/stdc++.h>
using namespace std;

int n, p, temp[10], visited[10];

void dfs(int start) {
    if (start == n + 1) {
        for (int i = 0; i < n; i++) {
            printf("%5d", temp[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            temp[p++] = i;
            visited[i] = 1;
            dfs(start + 1);
            visited[i] = 0;
            temp[p--] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}
