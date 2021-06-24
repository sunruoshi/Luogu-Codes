#include <cstdio>

using namespace std;

int main() {
    int n;
    float sum = 0.0, max = 0.0, min = 10.0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        float score;
        scanf("%f", &score);
        max = score > max ? score : max;
        min = score < min ? score : min;
        sum += score;
    }
    printf("%.2f", (sum - max - min) / (n - 2));
    return 0;
}
