#include <cstdio>
#define MAXN 15001

int freq[MAXN], A[MAXN], B[MAXN], C[MAXN], D[MAXN];

int main(){
    int n, m, sum;
    scanf("%d %d", &n, &m);
    int x[m + 1];
    for (int i = 1; i <= m; i++) {
        scanf("%d", &x[i]);
        freq[x[i]]++;
    }
    for (int t = 1; t * 9 < n; t++) {
        sum = 0;
        for(int d = 9 * t + 2; d <= n; d++){
            sum += freq[d - 9 * t - 1] * freq[d - 7 * t - 1];
            C[d - t] += freq[d] * sum;
            D[d] += freq[d - t] * sum;
        }
        sum = 0;
        for (int a = n - 9 * t - 1; a > 0; a--){
            sum += freq[a + 8 * t + 1] * freq[a + 9 * t + 1];
            A[a] += freq[a + 2 * t] * sum;
            B[a + 2 * t] += freq[a] * sum;
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%d %d %d %d\n", A[x[i]], B[x[i]], C[x[i]], D[x[i]]);
    }
    return 0;
}
