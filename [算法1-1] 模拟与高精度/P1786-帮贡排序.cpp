#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> positions;

struct User {
    string name;
    string pos;
    int credit;
    int level;
    int index;
};

bool cmp1(User u1, User u2) {
    return u1.credit != u2.credit ? u1.credit > u2.credit : u1.index < u2.index;
}

bool cmp2(User u1, User u2) {
    bool flag;
    if (u1.pos != u2.pos) {
        flag = positions[u1.pos] > positions[u2.pos];
    } else if (u1.level != u2.level) {
        flag = u1.level > u2.level;
    } else {
        flag = u1.index < u2.index;
    }
    return flag;
}

int main() {
    positions["BangZhu"] = 7;
    positions["FuBangZhu"] = 6;
    positions["HuFa"] = 5;
    positions["ZhangLao"] = 4;
    positions["TangZhu"] = 3;
    positions["JingYing"] = 2;
    positions["BangZhong"] = 1;
    int n, cnt = 0;
    cin >> n;
    User user[n];
    for (int i = 0; i < n; i++) {
        User u;
        cin >> u.name >> u.pos >> u.credit >> u.level;
        u.index = i;
        user[i] = u;
    }
    sort(user, user + n, cmp1);
    for (int i = 0; i < n; i++) {
        if (user[i].pos != "BangZhu" && user[i].pos != "FuBangZhu") {
            if (cnt < 2) {
                user[i].pos = "HuFa";
            } else if (cnt < 6) {
                user[i].pos = "ZhangLao";
            } else if (cnt < 13) {
                user[i].pos = "TangZhu";
            } else if (cnt < 38) {
                user[i].pos = "JingYing";
            } else {
                user[i].pos = "BangZhong";
            }
            cnt++;
        }
    }
    sort(user, user + n, cmp2);
    for (int i = 0; i < n; i++) {
        cout << user[i].name << " " << user[i].pos << " " << user[i].level << endl;
    }
    return 0;
}

