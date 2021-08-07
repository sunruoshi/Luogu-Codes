#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> fa;

string f, s;

string Find(string x) {
    if (x != fa[x]) fa[x] = Find(fa[x]);
    return fa[x];
}

int main() {
    while (1) {
        char opt;
        cin >> opt;
        if (opt == '$') break;
        cin >> s;
        if (opt == '#') {
            f = s;
            if (fa[s] == "") fa[s] = s;
        } else if (opt == '+') {
            fa[s] = f;
        } else {
            cout << s << ' ' << Find(s) << endl;
        }
    }
    return 0;
}
