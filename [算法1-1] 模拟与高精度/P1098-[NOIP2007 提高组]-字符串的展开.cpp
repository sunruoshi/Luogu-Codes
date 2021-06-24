#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isLetter(char c) {
    return c >= 'a' && c <= 'z';
}

bool check(char a, char b) {
    return (isDigit(a) && isDigit(b) || isLetter(a) && isLetter(b)) && b > a;
}

string format(char first, char last, int p1, int p2, int p3) {
    string s = "";
    if (last - first == 1) return s;
    if (p1 == 3) {
        for (int i = first - '0' + 1; i < last - '0'; i++) {
            string temp (p2, '*');
            s += temp;
        }
        return s;
    }
    if (isDigit(first)) {
        for (int i = first + 1; i < last; i++) {
            string temp (p2, i);
            s += temp;
        }
    } else {
        if (p1 == 1) {
            for (int i = first + 1; i < last; i++) {
                string temp (p2, i);
                s += temp;
            }
        } else {
            for (int i = first - 'a' + 1; i < last - 'a'; i++) {
                string temp (p2, i + 'A');
                s += temp;
            }
        }
    }
    if (p3 == 2) {
        reverse(s.begin(), s.end());
    }
    return s;
}

int main () {
    int p1, p2, p3;
    string s;
    cin >> p1 >> p2 >> p3 >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-' && check(s[i - 1], s[i + 1])) {
            string alt = format(s[i - 1], s[i + 1], p1, p2, p3);
            s.replace(i, 1, alt);
        }
    }
    cout << s;
    return 0;
}
