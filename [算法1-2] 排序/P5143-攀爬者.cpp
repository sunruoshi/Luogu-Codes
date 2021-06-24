#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
    int x;
    int y;
    int z;
};

bool cmp(Point p1, Point p2) {
    return p1.z < p2.z;
}

double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

int main() {
    int n;
    scanf("%d", &n);
    Point points[n];
    for (int i = 0; i < n; i++) {
        Point p;
        scanf("%d %d %d", &p.x, &p.y, &p.z);
        points[i] = p;
    }
    sort(points, points + n, cmp);
    double ans = 0.0;
    for (int i = 0; i < n - 1; i++) {
        ans += dist(points[i], points[i + 1]);
    }
    printf("%.3lf", ans);
    return 0;
}
