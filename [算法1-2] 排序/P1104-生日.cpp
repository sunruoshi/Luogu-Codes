#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Stu {
    string name;
    int y;
    int m;
    int d;
    int id;
};

bool cmp(Stu s1, Stu s2) {
    if (s1.y != s2.y) return s1.y < s2.y;
    else if (s1.m != s2.m) return s1.m < s2.m;
    else if (s1.d != s2.d) return s1.d < s2.d;
    else return s1.id > s2.id;
}

int main() {
    int n;
    cin >> n;
    Stu students[n];
    for (int i = 0; i < n; i++) {
        Stu stu;
        cin >> stu.name >> stu.y >> stu.m >> stu.d;
        stu.id = i;
        students[i] = stu;
    }
    sort(students, students + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << students[i].name << endl;
    }
    return 0;
}
