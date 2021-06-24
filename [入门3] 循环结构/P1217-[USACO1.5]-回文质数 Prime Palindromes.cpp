#include <cstdio>

using namespace std;

int isPrime(int d) {
    for (int i = 2; i * i <= d; ++i) {
        if (d % i == 0) return 0;
    }
    return 1;
}

int main() {
    int start, end;
    scanf("%d %d", &start, &end);
    if (start == 5) printf("5\n");
    if (start <= 7) printf("7\n");
    if (start <= 11) printf("11\n");
    // 三位回文数
    for (int d1 = 1; d1 <= 9; d1 += 2) {
        for (int d2 = 0; d2 <= 9; d2++) {
            int palindrome = 100 * d1 + 10 * d2 + d1;
            if (palindrome > end) return 0;
            if (palindrome < start) continue;
            if (isPrime(palindrome)) printf("%d\n", palindrome);
        }
    }
    // 五位回文数
    for (int d1 = 1; d1 <= 9; d1 += 2) {
        for (int d2 = 0; d2 <= 9; d2++) {
            for (int d3 = 0; d3 <= 9; d3++) {
                int palindrome = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + d1;
                if (palindrome > end) return 0;
                if (palindrome < start) continue;
                if (isPrime(palindrome)) printf("%d\n", palindrome);
            }
        }
    }
    // 七位回文数
    for (int d1 = 1; d1 <= 9; d1 += 2) {
        for (int d2 = 0; d2 <= 9; d2++) {
            for (int d3 = 0; d3 <= 9; d3++) {
                for (int d4 = 0; d4 <= 9; d4++) {
                    int palindrome = 1000000 * d1 + 100000 * d2 + 10000 * d3 + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
                    if (palindrome > end) return 0;
                    if (palindrome < start) continue;
                    if (isPrime(palindrome)) printf("%d\n", palindrome);
                }
            }
        }
    }
    return 0;
}
