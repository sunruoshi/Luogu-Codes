#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<string> ans1;
    int ans2 = 0;
    while (n--) {
        string name, msg;
        cin >> name >> msg;
        int cnt = 0, len = msg.size();
        for (int i = 0; i <= len - 3; i++) {
            string ss = msg.substr(i, 3);
            if (ss == "sos") cnt++;
        }
        if (cnt >= ans2) {
            if (cnt > ans2) ans1.clear();
            ans1.push_back(name);
            ans2 = cnt;
        }
    }
    for (const auto &name : ans1) {
        cout << name << ' ';
    }
    cout << endl << ans2;
    return 0;
}
