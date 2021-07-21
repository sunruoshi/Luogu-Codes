#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, ans = 1e9, s[11], b[11];
vector<int> temp;

void dfs(int cur) {
    if (cur > n) {
        if (temp.size()) {
            int ts = 1, tb = 0;
            for (int i = 0; i < temp.size(); i++) {
                ts *= s[temp[i]];
                tb += b[temp[i]];
            }
            ans = min(ans, abs(ts - tb));
        }
        return;
    }
    temp.push_back(cur);
    dfs(cur + 1);
    temp.pop_back();
    dfs(cur + 1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> b[i];
    }
    dfs(1);
    cout << ans;
    return 0;
}

