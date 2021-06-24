#include <cstdio>

int main() {
    int l, m, cnt;
    scanf("%d %d", &l, &m);
    int arr[l + 1];
    cnt = l + 1;
    for (int i = 0; i < l + 1; ++i) arr[i] = 1;
    for (int i = 0; i < m; ++i) {
        int start, end;
        scanf("%d %d", &start, &end);
        for (int j = start; j <= end; ++j) {
            if (arr[j] == 1) {
                arr[j]--;
                cnt--;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
