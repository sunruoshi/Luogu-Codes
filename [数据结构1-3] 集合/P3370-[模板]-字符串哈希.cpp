#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7, P = 1e7 + 19;

long long HashStr(string s) {
    long long id = 0;
    for (unsigned i = 0; i < s.size(); i++) {
        id = (id * P + s[i] - 'a') % MOD;
    }
    return id;
}

int main() {
    int n, ans = 1;
    cin >> n;
    vector<int> HashSet;
    while (n--) {
        string s;
        cin >> s;
        HashSet.push_back(HashStr(s));
    }
    sort(HashSet.begin(), HashSet.end());
    for (unsigned i = 1; i < HashSet.size(); i++) {
        if (HashSet[i] != HashSet[i - 1]) ans++;
    }
    cout << ans;
    return 0;
}
