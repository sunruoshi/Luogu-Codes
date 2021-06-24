#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, ans = pow(2, 31) - 1, s[11], b[11];

void dfs(int cur, vector<int>& temp) {
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
    dfs(cur + 1, temp);
    temp.pop_back();
    dfs(cur + 1, temp);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> b[i];
    }
    vector<int> temp;
    dfs(1, temp);
    cout << ans;
    return 0;
}
