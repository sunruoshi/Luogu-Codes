#include <bits/stdc++.h>
using namespace std;

int a, b, c, p, cnt, temp[10], visited[10];

void dfs(int start) {
    if (start == 10) {
        int n1 = 100 * temp[0] + 10 * temp[1] + temp[2];
        int n2 = 100 * temp[3] + 10 * temp[4] + temp[5];
        int n3 = 100 * temp[6] + 10 * temp[7] + temp[8];
        if (n1 * b == n2 * a && n1 * c == n3 * a) {
            cnt++;
            printf("%d %d %d\n", n1, n2, n3);
        }
    }
    for (int i = 1; i <= 9; i++) {
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
    scanf("%d %d %d", &a, &b, &c);
    dfs(1);
    if (!cnt) printf("No!!!");
    return 0;
}
