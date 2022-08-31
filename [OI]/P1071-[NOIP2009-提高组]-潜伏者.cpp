#include <iostream>
#include <string>
using namespace std;

string s1, s2, origin;
char code[26];
bool vis[26];
int cnt;

int main() {
    cin >> s1 >> origin >> s2;
    for (auto i = 0; i < origin.size(); i++) {
        if (!vis[origin[i] - 'A']) {
            vis[origin[i] - 'A'] = 1;
            cnt++;
        }
    }
    if (cnt < 26) {
        cout << "Failed" << endl;
        return 0;
    }
    for (auto i = 0; i < s1.size(); i++) {
        if (!code[s1[i] - 'A']) code[s1[i] - 'A'] = origin[i];
        else {
            if (code[s1[i] - 'A'] != origin[i]) {
                cout << "Failed" << endl;
                return 0;
            }
        }
    }
    for (auto c : s2) {
        cout << code[c - 'A'];
    }
    return 0;
}
