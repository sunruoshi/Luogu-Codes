#include <cstdio>

using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (a > c) {
        int temp = a;
        a = c;
        c = temp;
    }
    if (b > c) {
        int temp = b;
        b = c;
        c = temp;
    }
    printf("%d %d %d", a, b, c);
    return 0;
}

/* 扩展1：使用循环
int main() {
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < 3; i++) {
        int d;
        scanf("%d", &d);
        if (d > c) {
            a = b;
            b = c;
            c = d;
        } else if (d > b) {
            a = b;
            b = d;
        } else if (d > a) {
            a = d;
        }
    }
    printf("%d %d %d", a, b, c);
    return 0;
}
 */

/* 扩展2：位运算
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    if (a > c) {
        a ^= c;
        c ^= a;
        a ^= c;
    }
    if (b > c) {
        b ^= c;
        c ^= b;
        b ^= c;
    }
    printf("%d %d %d", a, b, c);
    return 0;
}
 */