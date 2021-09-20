#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;
priority_queue<int> pq;
vector<int> minimum; //최소한 필요한 마일리지

void mileageNeed(int applypeople, int student, int n) {
	int stu;


	while (applypeople--) {//학생별 마일리지 점수 입력
		cin >> stu;
		pq.push(stu);
	}

	if (applypeople < student) {
		minimum.push_back(0); //수강인원이 더 많으면 항상 참
		return;
	}

	while (student--) {//최소한 필요한 마일리지 저장
		stu = pq.top();
		 pq.pop();
	}
	 minimum.push_back(stu);
	 for (int i = 0; i < n; i++) {
		 cout << minimum[i] << ', ';
	 }
}

int mileageSort(int m, int n) {
	int subject = 0, i=0, num=0;
	sort(minimum.begin(), minimum.end());

	for (int i = 0; i < n; i++) {
		cout << minimum[i] << ', ';
	}
	while(m>0){
		if (minimum[i] == 0) {
			subject++; m -= 1;
		}
		else {
			num = m - minimum[i];
			if (num >= 0) {
				subject++; m = num;
			}
		}
	}
	return subject;
}

int main() {
	int n, m;
	int mileage;

	cin >> n >> m; //과목수, 마일리지 수

	int applypeople, student;//신청한 사람수, 수강인원
	while (n--) {
		cin >> applypeople >> student;
		mileageNeed(applypeople,student,n); 
	}

	mileage = mileageSort(m, n);
	cout << mileage;
}