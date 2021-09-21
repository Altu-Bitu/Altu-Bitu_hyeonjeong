#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;
priority_queue<int> pq;
vector<int> minimum; //최소한 필요한 마일리지

void mileageNeed(int applypeople, int student) {
	int stu = 0;
	int apply = applypeople;


	while (apply--) {//학생별 마일리지 점수 입력
		cin >> stu;
		pq.push(stu);
	}

	if (applypeople < student) {
		minimum.push_back(0); //수강인원이 더 많으면 항상 참
	}
	else {
		while (student--) {//최소한 필요한 마일리지 저장
			stu = pq.top();
			pq.pop();

		}
		minimum.push_back(stu);
	}

	while (!pq.empty()) {
		pq.pop();
	}

}

int mileageSort(int m, int n) {
	int subject = 0, num = 0, i = 0;
	sort(minimum.begin(), minimum.end());

	while (m > 0 && i < n) {
		if (minimum[i] == 0) {
			subject++; m = m - 1;
		}
		else {
			num = m - minimum[i];
			if (num >= 0) {
				subject++; m = num;
			}
			else
				break;
		}
		i++;
	}
	return subject;
}

int main() {
	int n, m;
	int mileage;

	cin >> n >> m; //과목수, 마일리지 수

	int applypeople, student;//신청한 사람수, 수강인원
	int i = n;
	while (i--) {
		cin >> applypeople >> student;
		mileageNeed(applypeople, student);
	}

	cout << mileageSort(m, n) << endl;


	return 0;
}