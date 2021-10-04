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
            int a = d - 9 * t - 1;
            int b = a + 2 * t;
            int c = d - t;
            sum += freq[a] * freq[b];
            C[c] += freq[d] * sum;
            D[d] += freq[c] * sum;
        }
        sum = 0;
        for (int a = n - 9 * t - 1; a > 0; a--){
            int b = a + 2 * t;
            int c = b + 6 * t + 1;
            int d = a + 9 * t + 1;
            sum += freq[c] * freq[d];
            A[a] += freq[b] * sum;
            B[b] += freq[a] * sum;
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%d %d %d %d\n", A[x[i]], B[x[i]], C[x[i]], D[x[i]]);
    }
    return 0;
}
