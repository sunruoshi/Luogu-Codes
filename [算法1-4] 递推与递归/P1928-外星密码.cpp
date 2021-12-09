#include <iostream>
#include <string>
using namespace std;

string solve() {
    string res = "";
    char c;
    while (cin >> c) {
        if (c == '[') {
            int n;
            cin >> n;
            string tmp = solve();
            while (n--) res += tmp;
        } else {
            if (c == ']') return res;
            else res += c;
        }
    }
    return res;
}

int main() {
    cout << solve();
    return 0;
}
