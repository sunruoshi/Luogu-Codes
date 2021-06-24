#include <cstdio>
#include <vector>
using namespace std;

int a, b, c, cnt;

void dfs(int start, vector<int>& temp, vector<int>& visited) {
    if (start == 10) {
        int n1 = 100 * temp[0] + 10 * temp[1] + temp[2];
        int n2 = 100 * temp[3] + 10 * temp[4] + temp[5];
        int n3 = 100 * temp[6] + 10 * temp[7] + temp[8];
        if (n1 * b == n2 * a && n1 * c == n3 * a) {
            cnt++;
            printf("%d %d %d\n", n1, n2, n3);
        }
    }
    for (int i = 1; i <= 9; i++) {
        if (!visited[i]) {
            temp.push_back(i);
            visited[i] = 1;
            dfs(start + 1, temp, visited);
            visited[i] = 0;
            temp.pop_back();
        }
    }
}

int main() {
    scanf("%d %d %d", &a, &b, &c);
    vector<int> temp, visited (10, 0);
    dfs(1, temp, visited);
    if (!cnt) printf("No!!!");
    return 0;
}
