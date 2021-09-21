#include <iostream>
#include <string>
using namespace std;

int n, ans, city[676][676];

int HashStr(string s) {
    return (s[0] - 'A') * 26 + s[1] - 'A';
}

int main() {
    cin >> n;
    while (n--) {
        string s1, s2;
        cin >> s1 >> s2;
        int id1 = HashStr(s1), id2 = HashStr(s2);
        if (id1 != id2) {
            city[id1][id2]++;
            ans += city[id2][id1];
        }
    }
    cout << ans;
    return 0;
}
