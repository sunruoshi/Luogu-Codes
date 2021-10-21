#include <cstdio>
#include <cstring>

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    int rails[n];
    memset(rails, 0, sizeof(rails));
    for (int i = 0; i < n; i++) {
        int num, pos;
        scanf("%d", &num);
        if (num > rails[cnt]) {
            pos = ++cnt;
        } else {
            int left = 0, right = cnt;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (rails[mid] >= num) right = mid;
                else left = mid + 1;
            }
            pos = left;
        }
        rails[pos] = num;
    }
    printf("%d", cnt);
    return 0;
}
