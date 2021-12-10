#include <cstdio>
#include <cmath>

int main() {
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    for (double i = -100; i <= 100; i += 0.001) {
        if (fabs(i * i * i * a + i * i * b + i * c + d) < 0.0001) printf("%.02lf ", i);
    }
    return 0;
}
