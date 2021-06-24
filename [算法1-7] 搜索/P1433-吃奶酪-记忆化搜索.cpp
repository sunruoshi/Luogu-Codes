#include <cstdio>
#include <cmath>
using namespace std;

int n, visited[16];
double ans = 1.79769e+308, points[16][2], dis[16][16], states[32768][16];

double getDist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void dfs(int prev, double dist, int start, int state) {
    if (dist >= ans) return;
    if (start == n) {
        ans = dist;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            double cur = dis[i][prev];
            int ns = state + (1 << (i - 1));
            if (states[ns][i] != 0 && states[ns][i] <= dist + cur) continue;
            states[ns][i] = dist + cur;
            visited[i] = 1;
            dfs(i, states[ns][i], start + 1, ns);
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf %lf", &points[i][0], &points[i][1]);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dis[i][j] = getDist(points[i][0], points[i][1], points[j][0], points[j][1]);
        }
    }
    dfs(0, 0, 0, 0);
    printf("%.2lf", ans);
    return 0;
}
