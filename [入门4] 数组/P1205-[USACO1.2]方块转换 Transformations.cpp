#include <cstdio>

int n;
// s：原始矩阵 t：目标矩阵 c：经过变换之后的矩阵 d：原始矩阵的备份
char s[10][10], t[10][10], c[10][10], d[10][10];

// 变换1：顺时针转90度
void t1() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) c[i][j] = s[n - j - 1][i];
    }
}

// 变换2：顺时针转180度
void t2() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) c[i][j] = s[n - i - 1][n - j - 1];
    }
}

// 变换2：顺时针转270度
void t3() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) c[i][j] = s[j][n - i - 1];
    }
}

// 变换4：镜像反转
void t4() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) c[i][j] = s[i][n - j - 1];
    }
}

// 比较经过变换后的矩阵是否跟结果相同
bool cmp() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (c[i][j] != t[i][j]) return false;
        }
    }
    return true;
}

bool r1() {
    t1();
    return cmp();
}

bool r2() {
    t2();
    return cmp();
}

bool r3() {
    t3();
    return cmp();
}

bool r4() {
    t4();
    return cmp();
}

bool r5() {
    t4();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) s[i][j] = c[i][j];
    }
    return r1() || r2() || r3();
}

bool r6() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][j] != t[i][j]) return false;
        }
    }
    return true;
}

int main() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
    for (int i = 0; i < n; ++i) scanf("%s", t[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) d[i][j] = s[i][j];
    }
    if (r1()) printf("1");
    else if (r2()) printf("2");
    else if (r3()) printf("3");
    else if (r4()) printf("4");
    else if (r5()) printf("5");
    else if (r6()) printf("6");
    else printf("7");
    return 0;
}
