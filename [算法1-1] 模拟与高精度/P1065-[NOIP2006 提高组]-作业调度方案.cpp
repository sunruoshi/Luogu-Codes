#include <iostream>
using namespace std;

struct Info {
    int id;
    int cost;
};

int machine[21][8000], step[21], last[21];

int main() {
    int m, n, ans = 0;
    cin >> m >> n;
    int order[m * n + 1];
    Info part[n + 1][m + 1];
    for (int i = 1; i <= m * n; i++) {
        cin >> order[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> part[i][j].id;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> part[i][j].cost;
        }
    }
    for (int i = 1; i <= m * n; i++) {
        int cur = order[i], t = 0;
        step[cur]++;
        int id = part[cur][step[cur]].id, cost = part[cur][step[cur]].cost, j = last[cur] + 1;
        while (true) {
            t = machine[id][j] == 0 ? t + 1 : 0;
            if (t == cost) {
                for (int k = j - cost + 1; k <= j; k++) {
                    machine[id][k] = 1;
                }
                ans = j > ans ? j : ans;
                last[cur] = j;
                break;
            }
            j++;
        }
    }
    cout << ans;
    return 0;
}
