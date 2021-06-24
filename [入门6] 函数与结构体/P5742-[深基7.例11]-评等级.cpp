#include <iostream>
using namespace std;

struct Student {
	int id;
	int s1;
	int s2;
	double score;
	int sum();
};

int Student::sum() {
	return s1 + s2;
}

void judge(Student stu) {
	if (stu.sum() > 140 && stu.score >= 80.0)
		cout << "Excellent" << endl;
	else
		cout << "Not excellent" << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Student stu;
		cin >> stu.id >> stu.s1 >> stu.s2;
		stu.score = 0.7 * stu.s1 + 0.3 * stu.s2;
		judge(stu);
	}
	return 0;
}