#include <bits/stdc++.h>
using namespace std;

int n, r, p, temp[21];

void dfs(int cur) {
    if (cur > n || p == r) {
        if (p == r) {
            for (int i = 0; i < r; i++) {
                printf("%3d", temp[i]);
            }
            printf("\n");
        }
        return;
    }
    temp[p++] = cur;
    dfs(cur + 1);
    temp[p--] = 0;
    dfs(cur + 1);
}

int main() {
    scanf("%d %d", &n, &r);
    dfs(1);
    return 0;
}
