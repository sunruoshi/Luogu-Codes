#include <iostream>
#include <vector>
using namespace std;

int n, ans, num[1000] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int cost(int d) {
    if (num[d]) return num[d];
    else {
        int t = 0, n = d;
        while (n > 0) {
            t += num[n % 10];
            n /= 10;
        }
        num[d] = t;
        return t;
    }
}

void dfs(int cur, int sum, vector<int>& temp) {
    if (sum >= n - 4 || temp.size() == 3) {
        if (temp.size() == 3 && temp[0] + temp[1] == temp[2] && sum == n - 4) ans++;
        return;
    }
    for (int i = 0; i < 1000; i++) {
        sum += cost(i);
        temp.push_back(i);
        dfs(i + 1, sum, temp);
        temp.pop_back();
        sum -= cost(i);
    }
}

int main() {
    cin >> n;
    vector<int> temp;
    dfs(0, 0, temp);
    cout << ans;
    return 0;
}
