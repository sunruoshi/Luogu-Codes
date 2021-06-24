#include <cstdio>
#include <vector>
using namespace std;

int n, sum;

void dfs(vector<int>& temp, vector<vector<int> >& ans) {
    if (temp.size() == 10) {
        if (sum == n) ans.push_back(temp);
        return;
    }
    for (int i = 1; i <= 3; i++) {
        temp.push_back(i);
        sum += i;
        dfs(temp, ans);
        sum -= i;
        temp.pop_back();
    }
}

int main() {
    scanf("%d", &n);
    vector<int> temp;
    vector<vector<int> > ans;
    dfs(temp, ans);
    printf("%d\n", ans.size());
    if (ans.size()) {
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
