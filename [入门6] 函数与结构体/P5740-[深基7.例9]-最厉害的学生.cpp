#include <iostream>
#include <string>
using namespace std;

struct Student {
	string name;
	int s1;
	int s2;
	int s3;
};

int main() {
	int n;
	Student best;
	best.s1 = best.s2 = best.s3 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Student stu;
		cin >> stu.name >> stu.s1 >> stu.s2 >> stu.s3;
		if (stu.s1 + stu.s2 + stu.s3 > best.s1 + best.s2 + best.s3) {
			best.s1 = stu.s1;
			best.s2 = stu.s2;
			best.s3 = stu.s3;
			best.name = stu.name;
		}
	}
	cout << best.name << ' ' << best.s1 << ' ' << best.s2 << ' ' << best.s3;
	return 0;
}