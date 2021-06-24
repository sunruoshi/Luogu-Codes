#include <cstdio>
#include <vector>
using namespace std;

int n, r;

void dfs(int cur, vector<int>& temp) {
    if (cur > n || temp.size() == r) {
        if (temp.size() == r) {
            for (int i = 0; i < temp.size(); i++) {
                printf("%3d", temp[i]);
            }
            printf("\n");
        }
        return;
    }
    temp.push_back(cur);
    dfs(cur + 1, temp);
    temp.pop_back();
    dfs(cur + 1, temp);
}

int main() {
    vector<int> temp;
    scanf("%d %d", &n, &r);
    dfs(1, temp);
    return 0;
}
