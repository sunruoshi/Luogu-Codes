#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

typedef long long ll;

ll gcd(ll x, ll y) {
    return x % y ? gcd(y, x % y) : y;
}

string s;
vector<ll> t, b;
vector<char> opt;
bool flag = 1;

int main() {
    cin >> s;
    // regular expression
    regex e("[0-9]+");
    smatch m;
    while (regex_search(s, m, e)) {
        if (flag) t.push_back(stoi(m[0]));
        else b.push_back(stoi(m[0]));
        flag = !flag;
        s = m.suffix();
        if (s.size() && (s[0] == '+' || s[0] == '-' || s[0] == '*')) opt.push_back(s[0]);
    }
    // calculate
    ll x = t[0], y = b[0]; 
    for (unsigned i = 1; i < t.size(); i++) {
        if (opt[i - 1] == '*') {
            x *= t[i];
            y *= b[i];
        } else if (opt[i - 1] == '+') {
            ll c = y * b[i];
            x = x * b[i] + t[i] * y;
            y = c;
        } else {
            ll c = y * b[i];
            x = x * b[i] - t[i] * y;
            y = c;
        }
    }
    // format thr answer
    if ((x > 0 && y < 0) || (x < 0 && y > 0)) cout << '-';
    x = abs(x);
    y = abs(y);
    ll g = gcd(x, y);
    x /= g;
    y /= g;
    if (x % y) cout << x << '/' << y << endl;
    else cout << x / y << endl;
    return 0;
}
