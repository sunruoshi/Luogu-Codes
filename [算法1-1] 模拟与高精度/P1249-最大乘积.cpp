#include <iostream>
#include <vector>
using namespace std;

vector<int> mul_int(vector<int> &A, int B) {
    vector<int> res;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i] * B;
        res.push_back(t % 10);
        t /= 10;
    }
    while (t > 0) {
        res.push_back(t % 10);
        t /= 10;
    }
    return res;
}

int main() {
    int n, sum = 0;
    vector<int> ans, res (1, 1);
    cin >> n;
    for (int i = 2; sum < n; i++) {
        ans.push_back(i);
        sum += i;
    }
    if (sum != n) ans.erase(ans.begin() + sum - n - 2);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
        res = mul_int(res, ans[i]);
    }
    cout << endl;
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
    }
    return 0;
}
