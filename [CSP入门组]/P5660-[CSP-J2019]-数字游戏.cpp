#include <iostream>
#include <string>
using namespace std;

int ans;

int main() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') ans++;
    }
    cout << ans;
    return 0;
}
