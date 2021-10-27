#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int votes[3], maxv = 0, cnt = 0;
        for (int i = 0; i < 3; i++) {
            scanf("%d", votes + i);
            if (votes[i] > maxv) maxv = votes[i];
        }
        for (int i = 0; i < 3; i++) {
            if (maxv == votes[i]) cnt++;
        }
        for (int i = 0; i < 3; i++) {
            if (votes[i] < maxv) printf("%d ", maxv - votes[i] + 1);
            else {
                if (cnt > 1) printf("1 ");
                else printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}
