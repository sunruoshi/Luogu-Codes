#include <bits/stdc++.h>
using namespace std;

int n, p, temp[10], visited[10];

void dfs(int len, int start) {
    if (start == len + 1) {
        for (int i = 0; i < n; i++) {
            printf("%5d", temp[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= len; i++) {
        if (!visited[i]) {
            temp[p++] = i;
            visited[i] = 1;
            dfs(len, start + 1);
            visited[i] = 0;
            temp[p--] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(n, 1);
    return 0;
}
