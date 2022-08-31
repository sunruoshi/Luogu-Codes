#include <iostream>
#include <string>
using namespace std;

int code[26][26];

string k, c;

inline char encode(char x, int i) {
    if (x >= 'A' && x <= 'Z') {
        return char(code[x - 'A'][k[i % k.size()] - 'a'] + 'A');
    } else {
        return char(code[x - 'a'][k[i % k.size()] - 'a'] + 'a');
    }
}

int main() {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            code[i][j] = (i + j) % 26;;
        }
    }
    cin >> k >> c;
    for (auto i = 0; i < k.size(); i++) {
        if (k[i] >= 'A' && k[i] <= 'Z') k[i] += 'a' - 'A';
    }
    for (auto i = 0; i < c.size(); i++) {
        for (int j = 0; j < 26; j++) {
            char x = c[i] >= 'A' && c[i] <= 'Z' ? j + 'A' : j + 'a';
            if (encode(x, i) == c[i]) {
                cout << x;
                break;
            }
        }
    }
    return 0;
}
